#ifndef GRAPH_H
#define GRAPH_H

#include "arch.h"
#include <QMouseEvent>
class Graph
{
public:

    //Constructors
    Graph();
    Graph(const Graph& g);
    ~Graph();

    //Getters
    node* getStart();
    std::vector<node*> getNodes();
    std::vector<Arch*> getArches();
    std::vector<node*> getNodesGraf();
    bool getWayOut();
    bool getPrintGraf();
    std::vector<std::vector<int>> getFileMatrix();

    //Setters
    void setPrintGraf(bool ok);
    void setStart(node* n);
    void setWayOut(bool ok);

    //Adding elemnets
    void addNode(node* n);
    void addNode(QPoint p);
    void addArch(Arch* arc);
    void addArch(node* firstNode, node* secondNode);


    //Data Structure
    void ReadFromFile(const QString& filename);
    void GrafFromMatrix();

    //Find functions
    node* FindNodeFromPozition(std::pair<int, int>poz);
    bool FindArch(node* first, node* second);
    void FindPathOut(node* start);

private:
    std::vector<node*> m_nodes;
    std::vector<node*>m_nodes_graf;
    std::vector<Arch*> m_arches;
    std::vector<std::vector<int>>m_FileMatrix;
    bool WayOut;
    bool PrintGraf;
    node* start;

};

#endif // GRAPH_H
