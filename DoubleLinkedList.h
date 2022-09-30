//
// Created by Antonio Nogueron Barcenas on 9/26/22.
//

#include "DoubleNodePointer.h"
#include <iostream>

using namespace std;

#pragma once
class DoubleLinkedList {
private:
    DoubleNodePointer* head;
public:
    DoubleLinkedList();
    ~DoubleLinkedList();

    void setHead(DoubleNodePointer*);
    DoubleNodePointer* getHead();

    void appendInOrder(int data);
    void printList();
    void remove(int data);
    void push_back(int data);
    void insert(int data);
    void pop_back();
    void pop_first();
    int getLength();
    bool isEmpty();
    DoubleNodePointer* find(int data);
    int getFirst();
    int getLast();
    int locate(int data);

    friend ostream& operator<<(ostream& os, DoubleLinkedList doubleList);
    DoubleLinkedList operator+(DoubleLinkedList lista2);
    void operator+=(int dato);
    void operator--();

    void removeDuplicates();
};