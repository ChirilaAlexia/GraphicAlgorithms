#ifndef GRAPHIC_H
#define GRAPHIC_H

#include "arch.h"
#include <QMouseEvent>

class Graphic
{
public:

    //Constructors
    Graphic();
    Graphic(const Graphic& g);

    //Destructor
    ~Graphic();

    //Getters
    std::vector<Node*> getNodes();
    std::vector<Arch*> getArches();

    //Setters
    void SetIsOriented(bool ok);

    //Add elements
    void addNode(Node* n);
    void addNode(QPoint p);
    void addArch(Arch* arc);
    void addArch(Node* firstNode, Node* secondNode);


    bool isMultigraph(Node* first, Node* second);

    void writeToFile(const QString& fileName);

    Node* Collision(QMouseEvent* e);

private:
    std::vector<Node*> nodes;
    std::vector<Arch*> arches;
    bool isOriented;



};

#endif // GRAPH_H
