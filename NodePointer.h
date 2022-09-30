// Antonio Noguerón & Armando Arredondo
// 09/29/2022

#include "Node.h"

#pragma once
class NodePointer : public Node{
private:
    NodePointer *next;
public:
    NodePointer();
    NodePointer(int);
    NodePointer(int, NodePointer*);

    void setNext(NodePointer*);

    NodePointer* getNext();
};
