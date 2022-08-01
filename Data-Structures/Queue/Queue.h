#pragma once

#include "../DoublyLinkedList/DLinkedList.h"

template <typename T>
class Queue {
    private:
        DoublyLinkedList<T> list;
    public:
        Queue ();

        Queue (const Queue<T> &other);

        ~Queue ();

        void push (T t);

        void pop ();

        T front ();

        void print_queue (std::ostream& os);

        friend std::ostream& operator<<(std::ostream& os, const Queue<T> &q);
};
