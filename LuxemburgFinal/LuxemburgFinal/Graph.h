#pragma once
#include <vector>
#include <unordered_map>
#include<string>

#include "Node.h"
#include "Arch.h"

class Graph {

public:
    //constructor
    Graph()=default;

    //Add
    void AddNode(Node* node);
    void AddArch(Arch* arch);

    //getter
    std::unordered_map<int, Node*>& GetNodes();
    std::unordered_map<int, std::vector<Arch*>>& GetVec();

    //read
    Graph* GraphFromFile(const std::string& filename);

    //Dijkstra
    std::vector<int> DijkstraQueue(int startNode, int endNode);
    

private:
    std::unordered_map<int, Node*> nodes;
    std::unordered_map<int, std::vector<Arch*>> vec;

};