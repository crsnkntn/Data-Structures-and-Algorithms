#include "DLinkedList.h"

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
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& other) {
    if (other.head == nullptr) {
        head = nullptr;
        size = 0;
    }
    impl::DoublyLinkedListNode<T>* iter = other.head;
    impl::DoublyLinkedListNode<T>* new_list_iter = new impl::DoublyLinkedListNode<T>();
    new_list_iter->datum = iter->datum;
    new_list_iter->next = nullptr;
    new_list_iter->prev = nullptr;
    head = new_list_iter;
    size = 1;

    iter = iter->next;
    while (iter != nullptr) {
        impl::DoublyLinkedListNode<T>* temp = new impl::DoublyLinkedListNode<T>();
        temp->datum = iter->datum;
        temp->next = nullptr;
        temp->prev = new_list_iter;
        new_list_iter->next = temp;
        new_list_iter = new_list_iter->next;
        iter = iter->next;
        size++;
    }
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
    new_node->prev = nullptr;
    new_node->datum = t;

    if (head == nullptr)
        head = new_node;
    else {
        impl::DoublyLinkedListNode<T>* iter = head;
        while (iter->next != nullptr)
            iter = iter->next;
        iter->next = new_node;
        new_node->prev = &(*iter);
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
        new_node->prev = &(*iter);
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
void DoublyLinkedList<T>::reverse () {
    if (head == nullptr)
        return;
    impl::DoublyLinkedListNode<T>* iter1 = head;
    impl::DoublyLinkedListNode<T>* iter2 = iter1->next;
    iter1->next = nullptr;
    while (iter2 != nullptr) {
        impl::DoublyLinkedListNode<T>* temp = iter2->next;
        iter2->next = &(*iter1);
        iter1->prev = &(*iter2);
        iter1 = iter2;
        iter2 = &(*temp);
    }
    head = &(*iter1);
}

template <typename T>
void DoublyLinkedList<T>::print_list (std::ostream& os) {
    impl::DoublyLinkedListNode<T>* ite = head;
    while (ite != nullptr) {
        os << "[" << ite->datum << "] -> ";
        ite = ite->next;
    }
    os << "END" << std::endl;
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

template <typename T>
void DoublyLinkedList<T>::insert_to_front (T t) {
    if (head == nullptr) {
        insert(t);
        return;
    }
    impl::DoublyLinkedListNode<T>* new_node = new impl::DoublyLinkedListNode<T>();
    new_node->datum = t;
    new_node->next = head;
    new_node->prev= nullptr;
    head->prev = new_node;
    head = new_node;
}

template <typename T>
void DoublyLinkedList<T>::insert_to_back (T t) {
    if (head == nullptr) {
        insert(t);
        return;
    }
    impl::DoublyLinkedListNode<T>* new_node = new impl::DoublyLinkedListNode<T>();
    impl::DoublyLinkedListNode<T>* iter = head;
    while (iter->next != nullptr)
        iter = iter->next;

    new_node->datum = t;
    new_node->next = nullptr;
    new_node->prev= iter;
    iter->next = new_node;
}

template <typename T>
void DoublyLinkedList<T>::remove_front () {
    if (head == nullptr)
        return;
    impl::DoublyLinkedListNode<T>* victim = head;
    head = head->next;
    delete victim;
}

template <typename T>
void DoublyLinkedList<T>::remove_back () {
    if (head == nullptr)
        return;

    impl::DoublyLinkedListNode<T>* victim = head;
    while (victim->next != nullptr)
        victim = victim->next;

    victim->prev->next = nullptr;
    delete victim;
}

template <typename T>
T DoublyLinkedList<T>::access_front () {
    return (head == nullptr) ? T() : head->datum;
}

template <typename T>
T DoublyLinkedList<T>::access_back () {
    if (head == nullptr)
        return T();
    impl::DoublyLinkedListNode<T>* iter = head;
    while (iter->next != nullptr)
        iter = iter->next;

    return iter->datum;
}
