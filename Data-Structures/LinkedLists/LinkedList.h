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
            explicit LinkedListIterator (LinkedListNode* n);

            // Operators
            T& operator*() const;
            LinkedListIterator& operator++();
            LinkedListIterator operator++(T t);
            bool operator==(const LinkedListIterator& rhs);
            bool operator!=(const LinkedListIterator& rhs);

        private:
            void store_nodes (LinkedListNode* n);

            std::vector<LinkedListNode*> nodes;

            std::vector<LinkedListNode*>::size_type current {0};
    };
}

template <typename T>
class LinkedList {
    public:
        using iterator = impl::BstIterator;
        LinkedList () = default;

        explicit LinkedList(std::initializer_list<T> il);

        ~LinkedList ();

        // Currently, the copy and move operations will not be supported.
        LinkedList(const LinkedList&) = delete;
        LinkedList(LinkedList&&) = delete;
        LinkedList& operator=(const LinkedList&) = delete;
        LinkedList& operator=(LinkedList&&) = delete;

        // Client API
        void insert (const T t);

        void insert_unique (const T t);

        void remove (const T t);

        void remove_all (const T t);

        friend std::ostream& operator<<(std::ostream& os, const LinkedList& l);

        // Iterators
        iterator begin() const;
        iterator end() const;
        
    private:
        size_t size;

        impl::LinkedListNode* head {nullptr};

        bool remove_helper (T t);
};