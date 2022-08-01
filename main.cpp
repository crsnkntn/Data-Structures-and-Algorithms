// Used to test each Data Structure 
#include "Data-Structures/LinkedLists/LinkedList.h"
#include "Data-Structures/LinkedLists/LinkedList.cpp"


int main () {
    LinkedList<int> ll {1, 2};

    ll.reverse();
    ll.reverse();

    for (const auto& n : ll) {
        std::cout << n << std::endl;
    }
    return 1;
}