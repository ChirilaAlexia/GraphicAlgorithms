#pragma once
class Arch
{
public:
   //constructor
    Arch(int from, int to, double length);

    //getter
    int GetFrom();
    int GetTo();
    double GetCost();

    //setter
    void SetFrom(int x);
    void SetTo(int y);
    void SetCost(int val);

private:
    int m_from, m_to;
    double m_cost;
};

