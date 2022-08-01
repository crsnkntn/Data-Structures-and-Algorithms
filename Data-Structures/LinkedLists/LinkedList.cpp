#include "LinkedList.h"

namespace impl {
    template <typename T>
    LinkedListIterator<T>::LinkedListIterator (LinkedListNode<T>* n) {
        store_nodes(n);

        nodes.push_back(nullptr);
    }

    template <typename T>
    T& LinkedListIterator<T>::operator*() const {
        return nodes[current]->datum;
    }

    template <typename T>
    LinkedListIterator<T>& LinkedListIterator<T>::operator++() {
        if (current == nodes.size() - 1)
            return *this;
        ++current;
        return *this;
    }

    template <typename T>
    LinkedListIterator<T> LinkedListIterator<T>::operator++(T t) {
        LinkedListIterator<T>* temp = *this;
        if (current == nodes.size() - 1)
            return temp;
        ++current;
        return temp;
    }

    template <typename T>
    bool LinkedListIterator<T>::operator==(const LinkedListIterator& rhs) {
        return nodes[current] == rhs.nodes[rhs.current];
    }

    template <typename T>
    bool LinkedListIterator<T>::operator!=(const LinkedListIterator& rhs) {
        return nodes[current] != rhs.nodes[rhs.current];
    }

    template <typename T>
    void LinkedListIterator<T>::store_nodes (LinkedListNode<T>* n) {
        if (n != nullptr) {
            nodes.push_back(n);
            store_nodes (n->next);
        }
    }
}

template <typename T>
LinkedList<T>::LinkedList (std::initializer_list<T> il) {
    for (const auto n : il)
        insert(n);
}

template <typename T>
LinkedList<T>::~LinkedList () {
    impl::LinkedListNode<T>* iter = head;
    while (iter != nullptr) {
        impl::LinkedListNode<T>* victim = iter;
        iter = iter->next;
        delete victim;
    }
}

template <typename T>
void LinkedList<T>::insert (T t) {
    impl::LinkedListNode<T>* new_node = new impl::LinkedListNode<T>();
    new_node->next = nullptr;
    new_node->datum = t;
    if (head == nullptr)
        head = new_node;
    else {
        impl::LinkedListNode<T>* iter = head;
        while (iter->next != nullptr)
            iter = iter->next;
        iter->next = new_node;
    }
    size++;
}

template <typename T>
void LinkedList<T>::insert_unique (T t) {
    impl::LinkedListNode<T>* new_node = new impl::LinkedListNode<T>(nullptr, t);
    if (head == nullptr)
        head = new_node;
    else {
        impl::LinkedListNode<T>* iter = head;
        while (iter->next != nullptr) {
            if (iter->datum == t)
                return;
            iter = iter->next;
        }
        iter->next = new_node;
    }
    size++;
}

template <typename T>
void LinkedList<T>::remove (T datum) {
    remove_helper(datum);
}

template <typename T>
void LinkedList<T>::remove_all (T datum) {
    while (remove_helper(datum)) {}
}

template <typename T>
bool LinkedList<T>::remove_helper (T datum) {
    if (head == nullptr)
        return false;
    
    impl::LinkedListNode<T>* iter = head, prev = nullptr;
    while (iter != nullptr) {
        if (iter->datum == datum) {
            prev->next = iter->next;
            delete iter;
            return true;
        }
        prev = iter;
        iter = iter->next;
    }
    return false;
}

template <typename T>
void LinkedList<T>::reverse () {
    if (head == nullptr)
        return;
    impl::LinkedListNode<T>* iter1 = head;
    impl::LinkedListNode<T>* iter2 = iter1->next;
    iter1->next = nullptr;
    while (iter2 != nullptr) {
        impl::LinkedListNode<T>* temp = iter2->next;
        iter2->next = &(*iter1);
        iter1 = iter2;
        iter2 = &(*temp);
    }
    head = &(*iter1);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& l) {
    impl::LinkedListNode<T>* ite = l.head;
    os << "List: ";
    while (ite != nullptr) {
        os << "[" << ite->datum << "] -> ";
        ite = ite->next;
    }
    os << "END" << std::endl;

    return os;
}

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::begin () const {
    return impl::LinkedListIterator<T>(head);
}

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::end () const {
    return impl::LinkedListIterator<T>(nullptr);
}
