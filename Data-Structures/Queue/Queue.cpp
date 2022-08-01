#include "Queue.h"
#include "../DoublyLinkedList/DLinkedList.h"
#include "../DoublyLinkedList/DLinkedList.cpp"

template <typename T>
Queue<T>::Queue () {}

template <typename T>
Queue<T>::Queue (const Queue<T>& other) {
    list = DoublyLinkedList<T>(other);
}

template <typename T>
Queue<T>::~Queue () {}

template <typename T>
void Queue<T>::push (T t) {
    list.insert_to_front(t);
}

template <typename T>
void Queue<T>::pop () {
    list.remove_front();
}

template <typename T>
T Queue<T>::front () {
    return list.access_front();
}

template <typename T>
void Queue<T>::print_queue (std::ostream& os) {
    list.print_list(os);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Queue<T>& q) {
    os << q.list << std::endl;
    return os;
}