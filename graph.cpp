#include "graph.h"
#include <fstream>
#include <vector>
#include <QFile>
#include <QTextStream>
#include <QMouseEvent>
#include <fstream>
#include <queue>

Graph::Graph()
{
    WayOut = false;
    PrintGraf = false;
    start = nullptr;
}

std::vector<node*> Graph::getNodes()
{
    return m_nodes;
}

std::vector<Arch*> Graph::getArches()
{
    return m_arches;
}

std::vector<node*> Graph::getNodesGraf()
{
    return m_nodes_graf;
}

bool Graph::getWayOut()
{
    return this->WayOut;
}

void Graph::setPrintGraf(bool ok)
{
    this->PrintGraf = ok;
}

void Graph::setStart(node* n)
{
    this->start = n;
}

node* Graph::getStart()
{
    return start;
}

bool Graph::getPrintGraf()
{
    return this->PrintGraf;
}

void Graph::setWayOut(bool ok)
{
    this->WayOut = ok;
}

void Graph::addNode(QPoint p)
{
    node* n = new node();
    n->setCoordinate(p);
    n->setColour("");
    n->setMatrixpozition(-1, -1);
    m_nodes.push_back(n);
}

Graph::Graph(const Graph& g)
{
    std::vector<node*>noduri;
    this->WayOut = g.WayOut;
    this->PrintGraf = g.PrintGraf;
    this->start = g.start;
    for (auto n : g.m_nodes)
    {
        node* aux = new node;
        aux->setCoordinate(n->getCoordinate());
        aux->setColour("");
        aux->setMatrixpozition(-1, -1);
        noduri.push_back(aux);
    }
    this->m_nodes = noduri;
    std::vector<Arch*>arce;
    for (auto a : g.m_arches)
    {
        Arch* arc = new Arch;
        for (auto n : this->m_nodes)
        {
            if (a->getFirstNode() == n)
            {
                arc->SetFirstNode(n);
            }
            if (a->getSecondNode() == n)
            {
                arc->SetSecondNode(n);
            }
        }
        arce.push_back(arc);

    }
    this->m_arches = arce;

}
Graph::~Graph()
{
    for (auto a : this->m_arches) {
        delete a;
    }
    for (auto n : this->m_nodes)
    {
        delete n;
    }
    for (auto n : this->m_nodes_graf)
    {
        delete n;
    }
}
void Graph::addArch(Arch* arc)
{
    m_arches.push_back(arc);
}

void Graph::addNode(node* n)
{
    m_nodes.push_back(n);
}

void Graph::addArch(node* firstNode, node* secondNode)
{
    Arch* arc = new Arch(firstNode, secondNode);
    m_arches.push_back(arc);

}
bool Graph::FindArch(node* first, node* second) {

    for (auto arch : m_arches)
    {
        if (arch->getFirstNode() == first && arch->getSecondNode() == second)
        {
            return true;
        }
    }
    return false;
}


void Graph::ReadFromFile(const QString& filename)
{

    std::ifstream f("date.in");
    if (!f.is_open())
    {
        qDebug() << "Error opening the file.\n";
        return;
    }
    int rows, columns;
    f >> rows >> columns;
    for (int i = 0; i < rows; i++)
    {
        std::vector<int> in;
        for (int j = 0; j < columns; j++)
        {
            int x;
            f >> x;
            in.push_back(x);
        }
        m_FileMatrix.push_back(in);
    }
    f.close();

}

void Graph::GrafFromMatrix()
{
    std::pair<int, int>coord;
    coord.first = 60;
    coord.second = 60;

    for (int i = 0; i < this->m_FileMatrix.size(); i++)
    {
        for (int j = 0; j < this->m_FileMatrix[i].size(); j++)
        {
            node* n = new node;
            n->setMatrixpozition(i, j);
            if (this->m_FileMatrix[i][j] == 0)
            {
                n->setColour("black");
            }
            else if (this->m_FileMatrix[i][j] == 1)
            {
                QPoint p(coord.first, coord.second);
                n->setCoordinate(p);
                n->setColour("white");
                this->m_nodes_graf.push_back(n);


            }
            else if (this->m_FileMatrix[i][j] == 2)
            {
                QPoint p(coord.first, coord.second);
                n->setCoordinate(p);
                n->setColour("red");
                this->m_nodes_graf.push_back(n);
            }
            else
            {
                QPoint p(coord.first, coord.second);
                n->setCoordinate(p);
                n->setColour("blue");
                setStart(n);
                this->m_nodes_graf.push_back(n);
            }

            this->m_nodes.push_back(n);
            coord.first += 40;
        }
        coord.second += 40;
        coord.first = 60;
    }

    for (auto node : getNodesGraf())
    {
        for (auto node2 : getNodesGraf())
        {
            if (node->getMatrixPozition() != node2->getMatrixPozition())
            {
                if (node->getCoordinate().y() == node2->getCoordinate().y() + 40 && node->getCoordinate().x() == node2->getCoordinate().x())
                {
                    addArch(node, node2);
                    addArch(node2, node);

                }
                if (node->getCoordinate().y() == node2->getCoordinate().y() && node->getCoordinate().x() == node2->getCoordinate().x() + 40)
                {
                    addArch(node, node2);
                    addArch(node2, node);

                }
            }
        }
    }
}


node* Graph::FindNodeFromPozition(std::pair<int, int>poz) {
    for (node* x : this->m_nodes) {
        if (x->getMatrixPozition() == poz)
            return x;
    }
    return nullptr;
}

std::vector<std::vector<int>> Graph::getFileMatrix()
{
    return m_FileMatrix;
}


void Graph::FindPathOut(node* start)
{
    std::vector<node*>U;
    std::queue<node*>V;
    std::vector<node*>W;
    std::map<node*, node*>predec;
    std::vector<std::vector<node*>>iesiri;
    std::map<node*, int>lungimi;

    V.push(start);
    for (auto x : m_nodes_graf)
    {
        if (start != x)
            U.push_back(x);
        predec.insert({ x, nullptr });
        lungimi.insert({ x, 0 });
    }
    while (!V.empty())
    {
        node* head = V.front();

        std::vector<node*>vecini;
        for (auto a : m_arches)
        {
            if (a->getFirstNode() == head)
                vecini.push_back(a->getSecondNode());
        }
        for (auto vec : vecini)
        {
            auto it = std::find(U.begin(), U.end(), vec);
            if (it != U.end())
            {
                V.push(vec);
                U.erase(it);
                predec[vec] = head;
                lungimi[vec] = lungimi[head] + 1;
                if (vec->getColour() == "red")
                {
                    std::vector<node*>road;
                    node* aux = vec;
                    while (aux != start)
                    {
                        road.push_back(aux);
                        aux = predec[aux];

                    }
                    road.push_back(start);
                    iesiri.push_back(road);
                }

            }
        }

        V.pop();
        W.push_back(head);
    }
    for (auto drum : iesiri)
    {
        for (auto road : drum)
        {
            if (road->getColour() == "white")
                road->setColour("green");
        }
    }

}