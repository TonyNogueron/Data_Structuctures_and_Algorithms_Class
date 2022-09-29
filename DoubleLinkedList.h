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

    /*
     Sobrecarga operador +(lista). Recibe una lista y el resultado debe ser una lista nueva con la
segunda lista concatenada al final. Cualquier de las dos listas pueden estar vacías. Ej. l3 = l1 +
l2, donde l1 es el objeto invocador, l2 sería el parámetro y l3 es una lista nueva con el
resultado de la suma de l1 y l2.
     */

    friend ostream& operator<<(ostream& os, DoubleLinkedList doubleList);
    friend DoubleLinkedList& operator+();
};