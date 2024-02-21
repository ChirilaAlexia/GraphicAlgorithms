#ifndef ARCH_H
#define ARCH_H

#include "node.h"

class Arch
{

public:
    Arch();
    Arch(Node* first, Node* second) :
        firstNode(first), secondNode(second)
    {
    }
    Node* getFirstNode() { return firstNode; }
    Node* getSecondNode() { return secondNode; }
    void SetFirstNode(Node* node) { this->firstNode = node; }
    void SetSecondNode(Node* node) { this->secondNode = node; }

private:
    Node* firstNode, * secondNode;
};

#endif // ARCH_H
