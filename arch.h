#ifndef ARCH_H
#define ARCH_H

#include "node.h"

class Arch
{

public:
    //Constructors
    Arch();
    Arch(node* first, node* second) :
        firstNode(first), secondNode(second)
    {
    }

    //Getters
    node* getFirstNode() { return firstNode; }
    node* getSecondNode() { return secondNode; }

    //Setters
    void SetFirstNode(node* node) { this->firstNode = node; }
    void SetSecondNode(node* node) { this->secondNode = node; }

private:
    node* firstNode, * secondNode;

};

#endif // ARCH_H
