#ifndef NODE_H
#define NODE_H
#include <QPainter>

class node
{
public:

    //Constructors
    node();
    node(int x, int y);
    node(QPoint p);

    //Setters
    void setCoordinate(QPoint);
    void setX(int x);
    void setY(int y);
    void setCoordinate(int x, int y);
    void setColour(const std::string& c);
    void setMatrixpozition(int i, int j);

    //Getters
    QPoint getCoordinate();
    int getX();
    int getY();
    std::string getColour();
    std::pair<int, int> getMatrixPozition();


private:
    QPoint coordinate;
    std::string colour;
    std::pair<int, int>MatrixPozition;

};

#endif // NODE_H
