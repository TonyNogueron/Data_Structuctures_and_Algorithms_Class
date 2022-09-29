//
// Created by Antonio Nogueron Barcenas on 9/26/22.
//

#include "Node.h"

#pragma once
class DoubleNodePointer : public Node {
private:
    DoubleNodePointer *next;
    DoubleNodePointer *prev;
public:
    DoubleNodePointer();
    DoubleNodePointer(int);

    void setNext(DoubleNodePointer*);
    void setPrev(DoubleNodePointer*);

    DoubleNodePointer* getNext();
    DoubleNodePointer* getPrev();
};
