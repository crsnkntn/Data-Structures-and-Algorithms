#pragma once

#include "../DoublyLinkedList/DLinkedList.h"
#include "../DoublyLinkedList/DLinkedList.cpp"

template <typename T>
class Stack {
    private:
        DoublyLinkedList<T> list;
    public:
        Stack ();

        Stack (const Stack<T> &other);

        ~Stack ();

        void push (T t);

        void pop ();

        T front ();

        void print_stack (std::ostream& os);

        friend std::ostream& operator<<(std::ostream& os, const Stack<T> &q);
};
