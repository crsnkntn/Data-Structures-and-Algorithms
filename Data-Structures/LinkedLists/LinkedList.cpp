#include "LinkedList.h"

// Default Constructor - Sets front and back to nullptr, size=0
template <typename T>
LinkedList<T>::LinkedList () {
    front = nullptr;
    back = nullptr;

    size = 0;
}

// Copy Constructor
template <typename T>
LinkedList<T>::LinkedList (const LinkedList& other) {
    if (other.size == 0) {
        front = nullptr;
        back = nullptr;
        size = 0;
    }

    Node* new_ite = new Node(other.front.datum, nullptr);
    Node* old_ite = other.front->next;

    while (old_ite != nullptr) {
        new_ite->next = new Node(old_ite->datum, nullptr);
        new_ite = new_ite->next;
        back = new_ite;
    }
}

// Destructor - Necessary because the new keyword is used to create Nodes!
template <typename T>
LinkedList<T>::~LinkedList () {
    Node* ite = front;
    while (ite != nullptr) {
        Node* victim = ite;
        ite = ite->next;
        delete victim;
    }
}

// Appends a new Node onto the back, thus creating a new back
template <typename T>
void LinkedList<T>::append (T datum) {
    Node* new_node = new Node(datum, nullptr);
    if (front == nullptr) {
        front = new_node;
        back = new_node;
    }
    back->next = new_node;
    back = new_node;
    size++;
}

template <typename T>
bool LinkedList<T>::remove_helper (T datum) {
    Node* ite = front;
    while (ite != nullptr) {
        Node* next = ite->next;
        if (next != nullptr && next->datum == datum) {
            ite->next = next->next;
            delete next;
            size--;
            return true;
        }
        ite = ite->next;
    }
    return false;
}

template <typename T>
void LinkedList<T>::remove (T datum) {
    while (remove_helper(datum)) {}
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