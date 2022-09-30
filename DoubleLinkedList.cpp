// Antonio Noguerón & Armando Arredondo
// 09/29/2022

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

void DoubleLinkedList::appendInOrder(int data) { // Complejidad O(N)
    DoubleNodePointer* newNode = new DoubleNodePointer(data); //Creamos el nuevo nodo
    if(isEmpty()){ // si está vacía entonces el nuevo nodo es la cabeza de la lista
        head = newNode;
    } else {
        DoubleNodePointer* previous = head, *aux = head; //Creamos nuestros apuntadores auxiliares
        while( aux != nullptr && aux->getData() <= data ){ //Nos movemos con los apuntadores hasta encontrar el lugar donde entra el nodo
            previous = aux;
            aux = aux->getNext();
        }
        if (aux == nullptr){ // si estamos al final
            previous->setNext(newNode);
            newNode->setPrev(previous);
        } else if (aux == previous){ // si va en el primer elemento
            newNode->setNext(head);
            head->setPrev(newNode);
            head = newNode;
        } else { // en cualquier otro caso
            previous->setNext(newNode);
            newNode->setNext(aux);
            newNode->setPrev(previous);
            aux->setPrev(newNode);
        }
    }
}

void DoubleLinkedList::printList() { // Complejidad O(N)
    string auxText;
    if(isEmpty()){
        cout << "The list is empty" << "\n";
    } else {
        DoubleNodePointer* aux = head;
        while(aux != nullptr){ // Vamos recorriendo la lista y formateamos el output
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

void DoubleLinkedList::remove(int data) { // Complejidad O(N)
    if (isEmpty()){ // Si está vacía no podemos eliminar e imprimimos que la lista está vacía.
        cout << "The list is empty" << "\n";
    } else {
        DoubleNodePointer *previous = head, *aux = head; // Creamos los apuntadores auxiliares
        while (aux != nullptr && aux->getData() != data) { //recorremos la lista buscando el elemento a borrar
            previous = aux;
            aux = aux->getNext();
        }
        if (aux == nullptr) { // si terminamos de recorrer es porque no hubo elemento
            cout << "Element was not found" << "\n";
        } else if (previous == aux) { // si era el primer elemento lo eliminamos
            head = aux->getNext();
            head->setPrev(nullptr);
            delete aux;
        } else { // Si se encuentra "en medio" conectamos los nodos y eliminamos el elemento
            previous->setNext(aux->getNext());
            if (aux->getNext() != nullptr){
                aux->getNext()->setPrev(previous);
            }
            delete aux;
        }
    }
}

void DoubleLinkedList::push_back(int data) { // Complejidad O(N)
    DoubleNodePointer* newNode = new DoubleNodePointer(data);
    if (head == nullptr){
        head = newNode;
    } else {
        DoubleNodePointer *previous = head, *aux = head;
        while (aux != nullptr){ // recorremos la lista y cuando encontremos un apuntador a null, es ahí donde insertamos el nuevo nodo
            previous = aux;
            aux = aux->getNext();
        }
        previous->setNext(newNode);
        newNode->setPrev(previous);
    }
}

void DoubleLinkedList::insert(int data) { // Complejidad O(1)
    DoubleNodePointer* newNode = new DoubleNodePointer(data);
    if (head == nullptr){ //Si está vacía el nuevo nodo es la cabeza
        head = newNode;
    } else { // si no, la cabeza es el segundo nodo, luego apuntamos a los nodos correctos y regresamos la cabeza al primer nodo
        newNode->setNext(head);
        head->setPrev(newNode);
        head = newNode;
    }
}

void DoubleLinkedList::pop_back() { // Complejidad O(N)
    if (isEmpty()){
        cout << "The list is empty" << "\n";
    } else {
        DoubleNodePointer *previous = head, *aux = head;
        while (aux->getNext() != nullptr) { // recorremos la lita y cuando llegamos al final, eliminamos el último elemento
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

void DoubleLinkedList::pop_first() { // Complejidad O(1)
    if (isEmpty()){
        cout << "The list is empty" << "\n";
    } else { // Eliminamos la cabeza y hacemos que el 2do elemento sea la nueva cabeza
        DoubleNodePointer* aux = head;
        aux->getNext()->setPrev(nullptr);
        head = aux->getNext();
        delete aux;
    }
}

DoubleNodePointer* DoubleLinkedList::find(int data) { // Complejidad O(N)
    if (isEmpty()){
        cout << "The list is empty" << "\n";
        return nullptr;
    } else {
        DoubleNodePointer *aux = head;
        while (aux != nullptr && aux->getData() != data) { // recorremos hasta encontrar el elemento y regresamos el NodoPtr
            aux = aux->getNext();
        }
        if (aux == nullptr) {
            return nullptr;
        } else {
            return aux;
        }
    }
}

int DoubleLinkedList::locate(int data) { // Complejidad O(N)
    if (isEmpty()){
        cout << "The list is empty" << "\n";
        return NULL;
    } else {
        DoubleNodePointer *aux = head;
        int answer = -1;
        while (aux != nullptr && aux->getData() != data) { //Recorremos hasta encontrar el elemento y regresamos el índice de su posición
            aux = aux->getNext();
            ++answer;
        }
        if (aux == nullptr) {
            cout << "Element was not found. ";
            return NULL;
        }
        return answer;
    }
}

int DoubleLinkedList::getLength() { // Complejidad O(N)
    int length = 0;
    if(isEmpty()){
        return 0;
    } else {
        DoubleNodePointer* aux = head;
        while(aux != nullptr){ // Recorremos la lista y llevamos un apuntador para contar los elementos
            ++length;
            aux = aux->getNext();
        }
    }
    return length;
}

int DoubleLinkedList::getFirst() { // Complejidad O(1)
    if (isEmpty()){
        cout << "The list is empty" << "\n";
        return NULL;
    } else {
        return head->getData();
    }
}

int DoubleLinkedList::getLast() { // Complejidad O(N)
    if (isEmpty()){
        cout << "The list is empty" << "\n";
        return NULL;
    } else {
        DoubleNodePointer* aux = head;
        while(aux->getNext() != nullptr) {
            aux = aux->getNext();
        }
        return aux->getData();
    }
}

bool DoubleLinkedList::isEmpty() { // Complejidad O(1)
    return (head == nullptr);
}

void DoubleLinkedList::removeDuplicates() { // Complejidad O(Nˆ2)
    if(isEmpty()){
        cout << "The list is empty \n";
    } else {
        DoubleNodePointer* previous = head, *aux = head;
        while(previous != nullptr){ // Recorremos cada elemento de la lista y con un apuntador auxiliar
            while(aux != nullptr){ // para cada elemento recorremos en busca de uno similar para eliminar aquel nodo donde aparezca
                aux = aux -> getNext();
                if (aux != nullptr && aux ->getData() == previous->getData()){
                    aux->getPrev()->setNext(aux->getNext());
                    if(aux->getNext() != nullptr){
                        aux->getNext()->setPrev(aux->getPrev());
                    }
                    delete aux;
                    aux = previous;
                }
            }
            previous = previous->getNext();
            aux = previous;
        }
    }
}

ostream& operator<<(ostream& os, DoubleLinkedList doubleList){ // Complejidad O(N)
    os << "|| Contenido de la lista ligada || \n" <<
          "================================== \n";
    if (doubleList.isEmpty()){
        return os;
    } else {
            DoubleNodePointer* aux = doubleList.getHead();
            string auxText = "";
            while(aux != nullptr){ //Recoremos la lista y damos el formato para imprimirla
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
        os << "\n";
        return os;
}

DoubleLinkedList DoubleLinkedList::operator+(DoubleLinkedList lista2) { // Complejidad O(N+M)
    DoubleLinkedList answer;
    DoubleNodePointer* previous = head, *aux = head;
    if(isEmpty()){
        if(lista2.isEmpty()){
            return answer;
        } else {
            aux = lista2.getHead();
            while (aux != nullptr) { // Si la primera lista está vacía, la respuesta es la lista 2, pero hay que copiar los elementos para no regresar la misma lista
                previous = aux;
                aux = aux->getNext();
                answer.push_back(previous->getData());
            }
            return answer;
        }
    } else {
        aux = head;
        while (aux != nullptr) { // añadimos los elementos de la lista 1
            previous = aux;
            aux = aux->getNext();
            answer.push_back(previous->getData());
        }
        if (!lista2.isEmpty()){
            aux = lista2.getHead();
            while (aux != nullptr) { // luego añadimos los de la lista 2
                previous = aux;
                aux = aux->getNext();
                answer.push_back(previous->getData());
            }
        }
        return answer;
    }
}

void DoubleLinkedList::operator+=(int dato) { // Complejidad O(N)
    appendInOrder(dato);
}

void DoubleLinkedList::operator--() { // Complejidad O(N)
    if(!isEmpty()){
        pop_back();
    }
}



