#ifndef ARCH_H
#define ARCH_H

#include "node.h"

class Arch
{

public:
    
    //Constructors
    Arch();
    Arch(Node* first, Node* second) :
        firstNode(first), secondNode(second)
    {
    }

    //Getters
    Node* getFirstNode() { return firstNode; }
    Node* getSecondNode() { return secondNode; }

    //Setters
    void SetFirstNode(Node* node) { this->firstNode = node; }
    void SetSecondNode(Node* node) { this->secondNode = node; }

private:
    Node* firstNode, * secondNode;
};

#endif // ARCH_H
