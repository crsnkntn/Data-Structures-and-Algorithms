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

        // Currently, the copy and move operations will not be supported.
        DoublyLinkedList(const DoublyLinkedList<T>&) = delete;
        DoublyLinkedList(DoublyLinkedList<T>&&) = delete;
        DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>&) = delete;
        DoublyLinkedList<T>& operator=(DoublyLinkedList<T>&&) = delete;

        // Client API
        void insert (const T t);

        void insert_unique (const T t);

        void remove (const T t);

        void remove_all (const T t);

        friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<T>& l);

        // Iterators
        iterator begin() const;
        iterator end() const;
        
    private:
        size_t size;

        impl::DoublyLinkedListNode<T>* head {nullptr};

        bool remove_helper (T t);
};