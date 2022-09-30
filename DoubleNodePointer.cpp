// Antonio Noguerón & Armando Arredondo
// 09/29/2022

#include "DoubleNodePointer.h"

DoubleNodePointer::DoubleNodePointer() {
    next = nullptr;
    prev = nullptr;
}

DoubleNodePointer::DoubleNodePointer(int data_) {
    next = nullptr;
    prev = nullptr;
    setData(data_);
}

void DoubleNodePointer::setNext(DoubleNodePointer *next_) {
    next = next_;
}

void DoubleNodePointer::setPrev(DoubleNodePointer *prev_) {
    prev = prev_;
}

DoubleNodePointer* DoubleNodePointer::getNext() {
    return next;
}

DoubleNodePointer* DoubleNodePointer::getPrev() {
    return prev;
}