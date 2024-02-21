#pragma once
class Node
{
public:
   
    //Constructors
    Node();
    Node(int id, double longitude, double latitude);

    //getter
    double x();
    double y();
    int GetValue();

    //setter
    void SetLong(double x);
    void SetValue(int val);
    void SetLat(double y);

private:
    int m_value;
    double m_longitude, m_latitude;
    
};

