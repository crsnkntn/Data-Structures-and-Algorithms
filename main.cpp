// Used to test each Data Structure 
#include "Data-Structures/DoublyLinkedList/DLinkedList.h"
#include "Data-Structures/DoublyLinkedList/DLinkedList.cpp"


int main () {
    DoublyLinkedList<int> ll {1, 2, 6, 3, 5, 3};

    ll.reverse();

    for (const auto& n : ll) {
        std::cout << n << std::endl;
    }
    return 1;
}