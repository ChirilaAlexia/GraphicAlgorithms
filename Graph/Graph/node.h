#ifndef NODE_H
#define NODE_H

#include <QPainter>

class Node
{
public:

    //Constructors
    Node();
    Node(int val);
    Node(int val, int x, int y);
    Node(int val, QPoint p);

    //Setters
    void setValue(int value);
    void setCoordinate(QPoint);
    void setX(int x);
    void setY(int y);
    void setCoordinate(int x, int y);
    void setSelect(bool ok); 


    //Getters
    bool getSelect(); 
    int getValue();
    QPoint getCoordinate();
    int getX();
    int getY();

    //Operators
    bool operator==(const Node& other);

private:
    int value;
    QPoint coordinate;
    bool isSelected;

};

#endif // NODE_H
