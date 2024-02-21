#include "node.h"

node::node()
{
    this->MatrixPozition.first = -1;
    this->MatrixPozition.second = -1;

}

node::node(int x, int y)
    :coordinate(x, y)
    , colour("null"),
    MatrixPozition({ -1,-1 })

{
}

node::node(QPoint point)
    : coordinate(point)
    , colour("null")
    , MatrixPozition({ -1,-1 })
{
}

void node::setCoordinate(QPoint p)
{
    coordinate = p;
}

int node::getX()
{
    return coordinate.x();
}
int node::getY()
{
    return coordinate.y();
}

void node::setX(int x)
{
    this->coordinate.setX(x);
}

void node::setY(int y)
{
    this->coordinate.setY(y);
}

void node::setCoordinate(int x, int y)
{
    this->coordinate.setX(x);
    this->coordinate.setY(y);
}

QPoint node::getCoordinate()
{
    return this->coordinate;
}

void node::setColour(const std::string& c)
{
    this->colour = c;
}

std::string node::getColour()
{
    return this->colour;
}

void node::setMatrixpozition(int i, int j)
{
    this->MatrixPozition.first = i;
    this->MatrixPozition.second = j;
}

std::pair<int, int> node::getMatrixPozition()
{
    return MatrixPozition;
}
