//
// Created by Antonio Nogueron Barcenas on 9/19/22.
//

#include "NodePointer.h"

NodePointer::NodePointer() {
    next = nullptr;
}

NodePointer::NodePointer(int data_) {
    next = nullptr;
    setData(data_);
}

NodePointer::NodePointer(int data_, NodePointer *pointer) {
    next = pointer;
    setData(data_);
}

void NodePointer::setNext(NodePointer *next_) {
    next = next_;
}

NodePointer* NodePointer::getNext() {
    return next;
}
