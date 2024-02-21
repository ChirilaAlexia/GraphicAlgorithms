#include "Node.h"

Node::Node() : m_value(-1), m_longitude(0.0), m_latitude(0.0) 
{
//empty
}
Node::Node(int id, double longitude, double latitude) : m_value(id), m_longitude(longitude), m_latitude(latitude)
{
    //empty
}
double Node::x()
{
    return m_longitude;
}

double Node::y()
{
    return m_latitude;
}

int Node::GetValue()
{
    return m_value;
}

void Node::SetLong(double x)
{
    m_longitude = x;
}

void Node::SetValue(int val)
{
    m_value = val;
}

void Node::SetLat(double y)
{
    m_latitude = y;
}
