#pragma once

#include <iostream>
#include <vector>
#include <initializer_list>

namespace impl {
    template <typename T>
    struct LinkedListNode {
        LinkedListNode<T>* next {nullptr};
        T datum {T()};
    };

    template <typename T>
    class LinkedListIterator {
        public:
            LinkedListIterator () = default;
            explicit LinkedListIterator (LinkedListNode<T>* n);

            // Operators
            T& operator*() const;
            LinkedListIterator<T>& operator++();
            LinkedListIterator<T> operator++(T t);
            bool operator==(const LinkedListIterator<T>& rhs);
            bool operator!=(const LinkedListIterator<T>& rhs);

        private:
            void store_nodes (LinkedListNode<T>* n);

            typename std::vector<LinkedListNode<T>*> nodes;

            typename std::vector<LinkedListNode<T>*>::size_type current {0};
    };
}

template <typename T>
class LinkedList {
    public:
        using iterator = impl::LinkedListIterator<T>;
        LinkedList () = default;

        explicit LinkedList(std::initializer_list<T> il);

        ~LinkedList ();

        // Currently, the copy and move operations will not be supported.
        LinkedList(const LinkedList<T>&) = delete;
        LinkedList(LinkedList<T>&&) = delete;
        LinkedList<T>& operator=(const LinkedList<T>&) = delete;
        LinkedList<T>& operator=(LinkedList<T>&&) = delete;

        // Client API
        void insert (const T t);

        void insert_unique (const T t);

        void remove (const T t);

        void remove_all (const T t);

        friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& l);

        // Iterators
        iterator begin() const;
        iterator end() const;
        
    private:
        size_t size;

        impl::LinkedListNode<T>* head {nullptr};

        bool remove_helper (T t);
};