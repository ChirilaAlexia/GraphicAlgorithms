#include "node.h"

Node::Node()
{
    value = -1;
    isSelected = false;
}
Node::Node(int val) : value(val), isSelected(false)
{
}

Node::Node(int val, int x, int y)
    : value(val)
    , coordinate(x, y)
    , isSelected(false)
{
}

Node::Node(int value, QPoint point)
    : value(value)
    , coordinate(point)
    , isSelected(false)
{
}

void Node::setValue(int value)
{
    this->value = value;
}

bool Node::getSelect()
{
    return this->isSelected;
}

int Node::getValue()
{
    return value;
}

void Node::setCoordinate(QPoint p)
{
    coordinate = p;
}

int Node::getX()
{
    return coordinate.x();
}
int Node::getY()
{
    return coordinate.y();
}

void Node::setX(int x)
{
    this->coordinate.setX(x);
}

void Node::setY(int y)
{
    this->coordinate.setY(y);
}

void Node::setCoordinate(int x, int y)
{
    this->coordinate.setX(x);
    this->coordinate.setY(y);
}

void Node::setSelect(bool ok)
{
    this->isSelected = ok;
}

QPoint Node::getCoordinate()
{
    return this->coordinate;
}
bool Node:: operator==(const Node& other)
{
    return (this->coordinate.x() == other.coordinate.x() && this->coordinate.y() == other.coordinate.y());
}
