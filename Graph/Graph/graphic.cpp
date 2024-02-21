#include "graphic.h"
#include <fstream>
#include <vector>
#include <QFile>
#include <QTextStream>
#include <QMouseEvent>

Graphic::Graphic()
{

}

void Graphic::SetIsOriented(bool ok) {
    isOriented = ok;
}
std::vector<Node*> Graphic::getNodes()
{
    return nodes;
}

std::vector<Arch*> Graphic::getArches()
{
    return arches;
}

void Graphic::addNode(QPoint p)
{
    Node* n = new Node();
    n->setCoordinate(p);
    n->setValue(nodes.size());
    nodes.push_back(n);
}
Graphic::Graphic(const Graphic& g)
{
    this->isOriented = g.isOriented;
    std::vector<Node*>noduri;
    for (auto n : g.nodes)
    {
        Node* aux = new Node;
        aux->setCoordinate(n->getCoordinate());
        aux->setValue(n->getValue());
        noduri.push_back(aux);
    }
    this->nodes = noduri;
    std::vector<Arch*>arce;
    for (auto a : g.arches)
    {
        Arch* arc = new Arch;
        for (auto n : this->nodes)
        {
            if (a->getFirstNode()->getValue() == n->getValue())
            {
                arc->SetFirstNode(n);
            }
            if (a->getSecondNode()->getValue() == n->getValue())
            {
                arc->SetSecondNode(n);
            }
        }
        arce.push_back(arc);

    }
    this->arches = arce;

}
Graphic::~Graphic()
{
    for (auto a : this->arches) {
        delete a;
    }
    for (auto n : this->nodes)
    {
        delete n;
    }
}
void Graphic::addArch(Arch* arc)
{
    arches.push_back(arc);
}

void Graphic::addNode(Node* n)
{
    nodes.push_back(n);
}

void Graphic::addArch(Node* firstNode, Node* secondNode)
{
    if (firstNode->getValue() == secondNode->getValue())
        return;
    Arch* arc = new Arch(firstNode, secondNode);
    arches.push_back(arc);

}
bool Graphic::isMultigraph(Node* first, Node* second) {

    for (auto arch : arches)
    {
        if (arch->getFirstNode() == first && arch->getSecondNode() == second)
        {
            return true;
        }
    }
    return false;
}

void Graphic::writeToFile(const QString& fileName)
{
    std::vector<std::vector<int>> matrix(nodes.size(), std::vector<int>(nodes.size(), 0));

    for (auto a : getArches()) {
        if (!isOriented) {
            matrix[a->getSecondNode()->getValue()][a->getFirstNode()->getValue()] = 1;
        }
        matrix[a->getFirstNode()->getValue()][a->getSecondNode()->getValue()] = 1;
    }

    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << matrix.size() << "\n";
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++)
                out << matrix[i][j] << " ";
            out << "\n";
        }
    }
    file.close();
}

Node* Graphic::Collision(QMouseEvent* e)
{
    std::vector<Node*> noduri = this->getNodes();
    for (auto n : noduri)
    {
        if (n->getX() == e->pos().x() || n->getY() == e->pos().y() || fabs(e->pos().x() - n->getX()) < 10 || fabs(e->pos().y() - n->getY()) < 10)
        {
            return n;
        }
    }
    return nullptr;
}
