// Used to test each Data Structure 
#include "Data-Structures/DoublyLinkedList/DLinkedList.h"
#include "Data-Structures/DoublyLinkedList/DLinkedList.cpp"
#include "Data-Structures/LinkedLists/LinkedList.h"
#include "Data-Structures/LinkedLists/LinkedList.cpp"


int main () {
    DoublyLinkedList<int> ll {1, 2, 3, 4, 5, 6};

    ll.reverse();

    DoublyLinkedList<int> newlist(ll);

    newlist.reverse();

    for (const auto& n : newlist) {
        std::cout << n << std::endl;
    }

    return 1;
}