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
    void LinkedListIterator<T>::sort_nodes (LinkedListNode<T>* n) {
        if (n != nullptr) {
            nodes.push_back(n);
            store_nodes (n->next);
        }
    }
}

template <typename T>
LinkedList<T>::LinkedList () { 
    size = 0; 
}

template <typename T>
LinkedList<T>::LinkedList (std::initializer_list<T> il) {
    for (const auto n : il)
        insert(n);
}

template <typename T>
LinkedList<T>::~LinkedList () {
    impl::LinkedListNode* iter = head;
    while (iter != nullptr) {
        impl::LinkedListNode* victim = iter;
        iter = iter->next;
        delete victim;
    }
}

template <typename T>
void LinkedList<T>::insert (T t) {
    impl::LinkedListNode* new_node = new impl::LinkedListNode(nullptr, t);
    if (head == nullptr)
        head = new_node;
    else {
        impl::LinkedListNode* iter = head;
        while (iter->next != nullptr)
            iter = iter->next;
        iter->next = new_node;
    }
    size++;
}

template <typename T>
void LinkedList<T>::insert_unique (T t) {
    impl::LinkedListNode* new_node = new impl::LinkedListNode(nullptr, t);
    if (head == nullptr)
        head = new_node;
    else {
        impl::LinkedListNode* iter = head;
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
    
    impl::LinkedListNode* iter = head, prev = nullptr;
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
void LinkedList<T>::print_list_contents () {
    Node* ite = front;
    std::cout << "List: ";
    while (ite != nullptr) {
        std::cout << "[" << ite->datum << "] -> ";
        ite = ite->next;
    }
    std::cout << "END" << std::endl;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList& l) {
    impl::LinkedListNode* ite = l.head;
    os << "List: ";
    while (ite != nullptr) {
        os << "[" << ite->datum << "] -> ";
        ite = ite->next;
    }
    os << "END" << std::endl;

    return os;
}

template <typename T>
LinkedList::iterator LinkedList<T>::begin () const {
    return impl::LinkedListIterator(head);
}

template <typename T>
LinkedList::iterator LinkedList<T>::end () const {
    return impl::LinkedListIterator(nullptr);
}
