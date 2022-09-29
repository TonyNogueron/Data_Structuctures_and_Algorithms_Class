//
// Created by Antonio Nogueron Barcenas on 9/22/22.
//

#include "LinkedList.h"
#include "NodePointer.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {

}

NodePointer *LinkedList::getHead() {
    return head;
}

void LinkedList::setHead(NodePointer * head_) {
    head = head_;
}

void LinkedList::appendInOrder(int data) {
    NodePointer* newNode = new NodePointer(data);
    if(head == nullptr){
        head = newNode;
    } else {
        NodePointer* previous = head, *aux = head;
        while(aux != nullptr && aux->getData() < data){
            previous = aux;
            aux = aux->getNext();
        }
        if (aux == nullptr){
            previous->setNext(newNode);
        } else if (aux == previous){
            newNode->setNext(head);
            head = newNode;
        } else {
            newNode->setNext(aux);
            previous->setNext(newNode);
        }
    }
}

void LinkedList::printList() {
    if(head == nullptr){
        cout << "The list is empty" << "\n";
    } else {
        NodePointer* aux = head;
        while(aux != nullptr){
            cout << aux->getData() << "\n";
            aux = aux->getNext();
        }
    }
}

void LinkedList::remove(int data) {
    if (head == nullptr){
        cout << "The list is empty" << "\n";
    } else {
        NodePointer *previous = head, *aux = head;
        while (aux != nullptr && aux->getData() != data) {
            previous = aux;
            aux = aux->getNext();
        }
        if (aux == nullptr) {
            cout << "Element was not found" << "\n";
        } else if (previous == aux) {
            head = aux->getNext();
            delete aux;
        } else {
            previous->setNext(aux->getNext());
            delete aux;
        }
    }
}

void LinkedList::push_back(int data) {
    NodePointer* newNode = new NodePointer(data);
    if (head == nullptr){
        head = newNode;
    } else {
        NodePointer *previous = head, *aux = head;
        while (aux != nullptr){
            previous = aux;
            aux = aux->getNext();
        }
        previous->setNext(newNode);
    }
}

void LinkedList::insert(int data) {
    NodePointer* newNode = new NodePointer(data);
    if (head == nullptr){
        head = newNode;
    } else {
        newNode->setNext(head);
        head = newNode;
    }
}

void LinkedList::pop_back() {
    if (head == nullptr){
        cout << "The list is empty" << "\n";
    } else {
        NodePointer *previous = head, *aux = head;
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

void LinkedList::pop_first() {
    if (head == nullptr){
        cout << "The list is empty" << "\n";
    } else {
        NodePointer* aux = head;
        head = aux->getNext();
        delete aux;
    }
}

NodePointer* LinkedList::find(int data) {
    if (head == nullptr){
        cout << "The list is empty" << "\n";
        return nullptr;
    } else {
        NodePointer *aux = head;
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






