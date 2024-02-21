#include "Graph.h"
#include <tinyxml2.h>
#include <iostream>
#include <queue>

void Graph::AddNode(Node* node)
{
	nodes[node->GetValue()] = node;
}

void Graph::AddArch(Arch* arch)
{
	vec[arch->GetFrom()].push_back(arch);
}

std::unordered_map<int, Node*>& Graph::GetNodes()
{
	return nodes;
}

std::unordered_map<int, std::vector<Arch*>>& Graph::GetVec()
{
	return vec;
}

Graph* Graph::GraphFromFile(const std::string& filename)
{
	Graph* g = new Graph();
	using namespace tinyxml2;
	XMLDocument doc;
	if (doc.LoadFile(filename.c_str()) != XML_SUCCESS) {
		std::cerr << "Nu se poate încărca fișierul XML." << std::endl;
		return nullptr;
	}

	XMLElement* root = doc.FirstChildElement("map");
	if (!root) {
		std::cerr << "Fișier XML invalid." << std::endl;
		return nullptr;
	}
	//noduri
	XMLElement* nodesElement = root->FirstChildElement("nodes");
	for (XMLElement* nodeElement = nodesElement->FirstChildElement("node"); nodeElement != nullptr; nodeElement = nodeElement->NextSiblingElement("node")) {
		int val = nodeElement->IntAttribute("id");
		double longitude = nodeElement->DoubleAttribute("longitude");
		double latitude = nodeElement->DoubleAttribute("latitude");

		Node* node=new Node(val, longitude, latitude);
		g->AddNode(node);
	}

	// arce
	XMLElement* arcsElement = root->FirstChildElement("arcs");
	for (XMLElement* arcElement = arcsElement->FirstChildElement("arc"); arcElement != nullptr; arcElement = arcElement->NextSiblingElement("arc")) {
		int from = arcElement->IntAttribute("from");
		int to = arcElement->IntAttribute("to");
		double cost = arcElement->DoubleAttribute("length");

		Arch* arch=new Arch(from, to, cost);
		g->AddArch(arch);
	}

	return g;
}

std::vector<int> Graph::DijkstraQueue(int startNode, int endNode)
{
	std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<>> queue;
	std::vector<double> distances(nodes.size(), std::numeric_limits<double>::max());
	std::vector<int> previous(nodes.size(), -1);

	distances[startNode] = 0;
	queue.push({ 0, startNode });

	while (!queue.empty()) {
		int currentNode = queue.top().second;
		queue.pop();

		// Parcurgem toate nodurile adiacente
		for ( auto arch : vec[currentNode]) {
			int neighbor = arch->GetTo();
			double newDist = distances[currentNode] + arch->GetCost();

			if (newDist < distances[neighbor]) {
				distances[neighbor] = newDist;
				previous[neighbor] = currentNode;
				queue.push({ newDist, neighbor });
			}
		}
	}

	// Reconstituim drumul
	std::vector<int> path;
	for (int at = endNode; at != -1; at = previous[at])
	{
		path.push_back(at);
	}
	std::reverse(path.begin(), path.end());

	return path;
}

