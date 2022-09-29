//
// Created by Antonio Nogueron Barcenas on 9/26/22.
//

#include "DoubleLinkedList.h"
#include "DoubleNodePointer.h"
#include <iostream>

using namespace std;

DoubleLinkedList::DoubleLinkedList() {
    head = nullptr;
}

DoubleLinkedList::~DoubleLinkedList() {

}

DoubleNodePointer *DoubleLinkedList::getHead() {
    return head;
}

void DoubleLinkedList::setHead(DoubleNodePointer * head_) {
    head = head_;
}

void DoubleLinkedList::appendInOrder(int data) {
    DoubleNodePointer* newNode = new DoubleNodePointer(data);
    if(isEmpty()){
        head = newNode;
    } else {
        DoubleNodePointer* previous = head, *aux = head;
        while(aux != nullptr && aux->getData() < data && aux->getNext() != nullptr && aux->getData() != aux->getNext()->getData()){
            previous = aux;
            aux = aux->getNext();
        }
        if (aux == nullptr){
            previous->setNext(newNode);
            newNode->setPrev(previous);
        } else if (aux == previous){
            newNode->setNext(head);
            head->setPrev(newNode);
            head = newNode;
        } else {
            newNode->setNext(aux);
            newNode->setPrev(previous);
            previous->setNext(newNode);
        }
    }
}

void DoubleLinkedList::printList() {
    string auxText = "";
    if(isEmpty()){
        cout << "The list is empty" << "\n";
    } else {
        DoubleNodePointer* aux = head;
        while(aux != nullptr){
            if (aux->getPrev() != nullptr){
                auxText = "<Previo: " + to_string(aux->getPrev()->getData());
            } else {
                auxText = "<Previo: NULL";
            }
            auxText += ", Dato: " + to_string(aux->getData()) + "> \n";
            cout << auxText;
            aux = aux->getNext();
        }
    }
}

void DoubleLinkedList::remove(int data) {
    if (head == nullptr){
        cout << "The list is empty" << "\n";
    } else {
        DoubleNodePointer *previous = head, *aux = head;
        while (aux != nullptr && aux->getData() != data) {
            previous = aux;
            aux = aux->getNext();
        }
        if (aux == nullptr) {
            cout << "Element was not found" << "\n";
        } else if (previous == aux) {
            aux->getNext()->setPrev(nullptr);
            head = aux->getNext();
            delete aux;
        } else {
            aux->getNext()->setPrev(previous);
            previous->setNext(aux->getNext());
            delete aux;
        }
    }
}

void DoubleLinkedList::push_back(int data) {
    DoubleNodePointer* newNode = new DoubleNodePointer(data);
    if (head == nullptr){
        head = newNode;
    } else {
        DoubleNodePointer *previous = head, *aux = head;
        while (aux != nullptr){
            previous = aux;
            aux = aux->getNext();
        }
        previous->setNext(newNode);
        newNode->setPrev(previous);
    }
}

void DoubleLinkedList::insert(int data) {
    DoubleNodePointer* newNode = new DoubleNodePointer(data);
    if (head == nullptr){
        head = newNode;
    } else {
        newNode->setNext(head);
        head->setPrev(newNode);
        head = newNode;
    }
}

void DoubleLinkedList::pop_back() {
    if (isEmpty()){
        cout << "The list is empty" << "\n";
    } else {
        DoubleNodePointer *previous = head, *aux = head;
        while (aux->getNext() != nullptr) {
            previous = aux;
            aux = aux->getNext();
        }
        if (aux->getNext() == nullptr) {
            previous->setNext(nullptr);
            delete aux;
        } else if (previous == aux) {
            head = nullptr;
            delete aux;
        }
    }
}

void DoubleLinkedList::pop_first() {
    if (isEmpty()){
        cout << "The list is empty" << "\n";
    } else {
        DoubleNodePointer* aux = head;
        aux->getNext()->setPrev(nullptr);
        head = aux->getNext();
        delete aux;
    }
}

DoubleNodePointer* DoubleLinkedList::find(int data) {
    if (isEmpty()){
        cout << "The list is empty" << "\n";
        return nullptr;
    } else {
        DoubleNodePointer *aux = head;
        while (aux != nullptr && aux->getData() != data) {
            aux = aux->getNext();
        }
        if (aux == nullptr) {
            return nullptr;
        } else {
            return aux;
        }
    }
}

int DoubleLinkedList::getLength() {
    int length = 0;
    if(isEmpty()){
        return 0;
    } else {
        DoubleNodePointer* aux = head;
        while(aux != nullptr){
            ++length;
            aux = aux->getNext();
        }
    }
    return length;
}

bool DoubleLinkedList::isEmpty() {
    return (head == nullptr);
}

ostream& operator<<(ostream& os, DoubleLinkedList doubleList)
{
    os << "|| Contenido de la lista ligada || \n" <<
          "================================== \n";
    if (doubleList.isEmpty()){
        return os;
    } else {
            DoubleNodePointer* aux = doubleList.getHead();
            string auxText = "";
            while(aux != nullptr){
                if (aux->getPrev() != nullptr){
                    auxText = "<Previo: " + to_string(aux->getPrev()->getData());
                } else {
                    auxText = "<Previo: NULL";
                }
                auxText += ", Dato: " + to_string(aux->getData());
                if (aux->getNext() != nullptr){
                    auxText += ", Siguiente: " + to_string(aux->getNext()->getData()) + "> \n";
                } else {
                    auxText += ", Siguiente: NULL> \n";
                }
                os << auxText;
                aux = aux->getNext();
            }
        }
        return os;
}

