//
// Created by Antonio Nogueron Barcenas on 9/19/22.
//
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
