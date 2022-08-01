#include "DoublyLinkedList.h"

namespace impl {
    template <typename T>
    DoublyLinkedListIterator<T>::DoublyLinkedListIterator (DoublyLinkedListNode<T>* n) {
        store_nodes(n);

        nodes.push_back(nullptr);
    }

    template <typename T>
    T& DoublyLinkedListIterator<T>::operator*() const {
        return nodes[current]->datum;
    }

    template <typename T>
    DoublyLinkedListIterator<T>& DoublyLinkedListIterator<T>::operator++() {
        if (current == nodes.size() - 1)
            return *this;
        ++current;
        return *this;
    }

    template <typename T>
    DoublyLinkedListIterator<T> DoublyLinkedListIterator<T>::operator++(T t) {
        DoublyLinkedListIterator<T>* temp = *this;
        if (current == 0)
            return temp;
        ++current;
        return temp;
    }

    template <typename T>
    DoublyLinkedListIterator<T>& DoublyLinkedListIterator<T>::operator--() {
        if (current == 0)
            return *this;
        --current;
        return *this;
    }

    template <typename T>
    DoublyLinkedListIterator<T> DoublyLinkedListIterator<T>::operator--(T t) {
        DoublyLinkedListIterator<T>* temp = *this;
        if (current == nodes.size() - 1)
            return temp;
        ++current;
        return temp;
    }

    template <typename T>
    bool DoublyLinkedListIterator<T>::operator==(const DoublyLinkedListIterator& rhs) {
        return nodes[current] == rhs.nodes[rhs.current];
    }

    template <typename T>
    bool DoublyLinkedListIterator<T>::operator!=(const DoublyLinkedListIterator& rhs) {
        return nodes[current] != rhs.nodes[rhs.current];
    }

    template <typename T>
    bool DoublyLinkedListIterator<T>::operator<(const DoublyLinkedListIterator& rhs) {
        return nodes[current] < rhs.nodes[rhs.current];
    }

    template <typename T>
    bool DoublyLinkedListIterator<T>::operator>(const DoublyLinkedListIterator& rhs) {
        return nodes[current] > rhs.nodes[rhs.current];
    }

    template <typename T>
    bool DoublyLinkedListIterator<T>::operator>=(const DoublyLinkedListIterator& rhs) {
        return nodes[current] >= rhs.nodes[rhs.current];
    }

    template <typename T>
    bool DoublyLinkedListIterator<T>::operator<=(const DoublyLinkedListIterator& rhs) {
        return nodes[current] <= rhs.nodes[rhs.current];
    }

    template <typename T>
    void DoublyLinkedListIterator<T>::store_nodes (DoublyLinkedListNode<T>* n) {
        if (n != nullptr) {
            nodes.push_back(n);
            store_nodes (n->next);
        }
    }
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList (std::initializer_list<T> il) {
    for (const auto n : il)
        insert(n);
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList () {
    impl::DoublyLinkedListNode<T>* iter = head;
    while (iter != nullptr) {
        impl::DoublyLinkedListNode<T>* victim = iter;
        iter = iter->next;
        delete victim;
    }
}

template <typename T>
void DoublyLinkedList<T>::insert (T t) {
    impl::DoublyLinkedListNode<T>* new_node = new impl::DoublyLinkedListNode<T>();
    new_node->next = nullptr;
    new_node->datum = t;
    if (head == nullptr)
        head = new_node;
    else {
        impl::DoublyLinkedListNode<T>* iter = head;
        while (iter->next != nullptr)
            iter = iter->next;
        iter->next = new_node;
    }
    size++;
}

template <typename T>
void DoublyLinkedList<T>::insert_unique (T t) {
    impl::DoublyLinkedListNode<T>* new_node = new impl::DoublyLinkedListNode<T>(nullptr, t);
    if (head == nullptr)
        head = new_node;
    else {
        impl::DoublyLinkedListNode<T>* iter = head;
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
void DoublyLinkedList<T>::remove (T datum) {
    remove_helper(datum);
}

template <typename T>
void DoublyLinkedList<T>::remove_all (T datum) {
    while (remove_helper(datum)) {}
}

template <typename T>
bool DoublyLinkedList<T>::remove_helper (T datum) {
    if (head == nullptr)
        return false;
    
    impl::DoublyLinkedListNode<T>* iter = head, prev = nullptr;
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
std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<T>& l) {
    impl::DoublyLinkedListNode<T>* ite = l.head;
    os << "List: ";
    while (ite != nullptr) {
        os << "[" << ite->datum << "] -> ";
        ite = ite->next;
    }
    os << "END" << std::endl;

    return os;
}

template <typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::begin () const {
    return impl::DoublyLinkedListIterator<T>(head);
}

template <typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::end () const {
    return impl::DoublyLinkedListIterator<T>(nullptr);
}
