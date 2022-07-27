#pragma once

#include <iostream>

template <typename T>
class LinkedList {
    private:
        struct Node {
            T datum;
            Node* next;

            Node (T d, Node* n) {
                datum = d;
                next = nullptr;
            }
        };

        // Attempts to remove one T with datum "datum"; if it exists return true, else return false
        bool remove_helper (T datum);

    public:
        LinkedList ();

        LinkedList (const LinkedList& other);

        ~LinkedList ();

        void append (T datum);

        void remove (T datum);

        void print_list_contents ();

    private:
        // The size of the LinkedList
        size_t size;

        // The front and back of the LinkedList
        Node* front;
        Node* back;
};