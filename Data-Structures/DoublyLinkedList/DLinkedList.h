#pragma once

#include <iostream>
#include <vector>
#include <initializer_list>

namespace impl {
    template <typename T>
    struct DoublyLinkedListNode {
        DoublyLinkedListNode<T>* next {nullptr};
        DoublyLinkedListNode<T>* prev {nullptr};
        T datum {T()};
    };

    template <typename T>
    class DoublyLinkedListIterator {
        public:
            DoublyLinkedListIterator () = default;
            explicit DoublyLinkedListIterator (DoublyLinkedListNode<T>* n);

            // Operators
            T& operator*() const;
            DoublyLinkedListIterator<T>& operator++();
            DoublyLinkedListIterator<T> operator++(T t);
            DoublyLinkedListIterator<T>& operator--();
            DoublyLinkedListIterator<T> operator--(T t);
            bool operator==(const DoublyLinkedListIterator<T>& rhs);
            bool operator!=(const DoublyLinkedListIterator<T>& rhs);
            bool operator<(const DoublyLinkedListIterator<T>& rhs);
            bool operator>(const DoublyLinkedListIterator<T>& rhs);
            bool operator<=(const DoublyLinkedListIterator<T>& rhs);
            bool operator>=(const DoublyLinkedListIterator<T>& rhs);

        private:
            void store_nodes (DoublyLinkedListNode<T>* n);

            typename std::vector<DoublyLinkedListNode<T>*> nodes;

            typename std::vector<DoublyLinkedListNode<T>*>::size_type current {0};
    };
}

template <typename T>
class DoublyLinkedList {
    public:
        using iterator = impl::DoublyLinkedListIterator<T>;
        DoublyLinkedList () = default;

        explicit DoublyLinkedList(std::initializer_list<T> il);

        ~DoublyLinkedList ();

        DoublyLinkedList(const DoublyLinkedList<T>& other);

        DoublyLinkedList(DoublyLinkedList<T>&&) = delete;
        DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>&) = delete;
        DoublyLinkedList<T>& operator=(DoublyLinkedList<T>&&) = delete;

        // Client API
        void insert (const T t);

        void insert_unique (const T t);

        void remove (const T t);

        void remove_all (const T t);

        void reverse ();

        void print_list (std::ostream& os);

        // Utility Functions to build on top of this class
        
        void insert_to_front (T t);

        void insert_to_back (T t);

        void remove_front ();

        void remove_back ();

        T access_front ();

        T access_back ();

        friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<T>& l);

        // Iterators
        iterator begin() const;
        iterator end() const;
        
    private:
        size_t size;

        impl::DoublyLinkedListNode<T>* head {nullptr};

        bool remove_helper (T t);
};