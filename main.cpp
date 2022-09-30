#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;

int main() {
    DoubleLinkedList l1, l2, l3, l4;
    l1.appendInOrder(5);
    l1.appendInOrder(4);
    l1.appendInOrder(25);
    l1.appendInOrder(10);
    l1.appendInOrder(0);
    l1.appendInOrder(4);
    l1.appendInOrder(5);

    l3.appendInOrder(34);
    l3.appendInOrder(89);
    l3.appendInOrder(12);
    l3.appendInOrder(6);
    l3.appendInOrder(45);

    l2.insert(12);
    l2.insert(13);
    l2.insert(5);
    l2.insert(48);
    l2.insert(50);

    cout << "Lista 1: \n " << l1;

    cout << "Lista 2: \n " << l2;

    l1 += 100;

    cout << "Lista 1: \n " << l1;

    l4 = l1 + l3;

    cout << "Lista 4: \n " << l4;

    --l3;

    cout << "Lista 3: \n " << l3;

    l1.removeDuplicates();

    cout << "Lista 1: \n " << l1;

    cout << "Longitud de la lista 1: " << l1.getLength() << "\n";

    cout << "El primer elemento es: " << l1.getFirst() << "\n";

    cout << "El último elemento es: " << l1.getLast() << "\n";

    cout << "El elemento 80 está en la posición: " << l2.locate(80) << "\n";

    cout << "El elemento 13 está en la posición: " << l2.locate(13) << "\n";

    return 0;
}
