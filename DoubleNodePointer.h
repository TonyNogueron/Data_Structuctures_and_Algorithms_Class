// Antonio Noguerón & Armando Arredondo
// 09/29/2022

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
