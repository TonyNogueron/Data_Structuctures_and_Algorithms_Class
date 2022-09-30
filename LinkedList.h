// Antonio Noguerón & Armando Arredondo
// 09/29/2022

#include "NodePointer.h"

#pragma once
class LinkedList {
private:
    NodePointer* head;
public:
    LinkedList();
    ~LinkedList();

    void setHead(NodePointer*);
    NodePointer* getHead();

    void appendInOrder(int data);
    void printList();
    void remove(int data);
    void push_back(int data);
    void insert(int data);
    void pop_back();
    void pop_first();
    NodePointer* find(int data);
};


