#include <iostream>
#include "LinkedList.h"
#include "DoubleLinkedList.h"

using namespace std;

int main() {
    LinkedList lista;
    DoubleLinkedList listaDoble;

    listaDoble.appendInOrder(1);
    listaDoble.appendInOrder(8);
    listaDoble.appendInOrder(5);
    listaDoble.appendInOrder(16);
    listaDoble.appendInOrder(8);
    listaDoble.printList();

    listaDoble.remove(16);
    cout << "\nDeleted element" << "\n";
    listaDoble.push_back(3);
    listaDoble.insert(69);
    listaDoble.printList();

    listaDoble.pop_back();
    cout << "\nPopped last" << "\n";
    listaDoble.printList();

    listaDoble.pop_first();
    cout << "\nPopped first" << "\n";
    listaDoble.printList();

    cout << "\nFind Method" << "\n";
    DoubleNodePointer* target = listaDoble.find(8);
    if (target == nullptr) {
        cout << "Element was not found" << "\n";
    } else {
        cout << "Element: " << target->getData() << " | Next pointer: " << target->getNext()
        << " | Previous pointer: " << target->getPrev() <<"\n";
    }

    cout << listaDoble;
    cout << listaDoble.getLength();
    return 0;
}
