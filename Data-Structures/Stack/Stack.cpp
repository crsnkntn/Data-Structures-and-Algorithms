#include "Stack.h"

template <typename T>
Stack<T>::Stack () {}

template <typename T>
Stack<T>::Stack (const Stack<T>& other) {
    list = DoublyLinkedList<T>(other);
}

template <typename T>
Stack<T>::~Stack () {}

template <typename T>
void Stack<T>::push (T t) {
    list.insert_to_back(t);
}

template <typename T>
void Stack<T>::pop () {
    list.remove_back();
}

template <typename T>
T Stack<T>::front () {
    return list.access_back();
}

template <typename T>
void Stack<T>::print_stack (std::ostream& os) {
    list.print_list(os);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& q) {
    os << q.list << std::endl;
    return os;
}