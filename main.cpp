#include <iostream>

#include "Data-Structures/Queue/Queue.h"
#include "Data-Structures/Queue/Queue.cpp"


int main () {
    Queue<int> q;
    q.push(5);
    q.push(9);
    q.push(9);
    q.push(9);
    q.push(5);
    q.push(66);
    q.push(88);
    q.push(445);
    q.print_queue(std::cout);
    for (int i = 0; i < 6; i++)
        q.pop();
    q.print_queue(std::cout);

    DoublyLinkedList<int> list {1, 2, 3, 4, 5};
    list.print_list(std::cout);


    return 1;
}