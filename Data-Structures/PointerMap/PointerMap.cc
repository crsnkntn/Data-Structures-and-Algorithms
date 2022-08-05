#include "PointerMap.h"

template <typename T>
PointerMapNode<T>::PointerMapNode () {
    datum = T();
    u = nullptr;
    r = nullptr;
    d = nullptr;
    l = nullptr;
}

template <typename T>
PointerMapNode<T>::PointerMapNode (T t) : datum(t) {
    u = nullptr;
    r = nullptr;
    d = nullptr;
    l = nullptr;
}

template <typename T>
PointerMap<T>::PointerMap (int w, int h) : map_width(w), map_height(h) {
    origin = new PointerMapNode<T>();

    construct_row(map_width, origin);

    auto prev_row = origin;
    for (int rows = map_height; rows > 0; rows--) {
        auto new_row = new PointerMapNode<T>();
        construct_row(map_width, new_row);

        auto iter1 = prev_row;
        auto iter2 = new_row;
        for (int cols = map_width; cols > 0; cols--) {
            iter1->d = iter2;
            iter2->u = iter1;
            iter1 = iter1->r;
            iter2 = iter2->r;
        }
        iter1 = nullptr;
        iter2 = nullptr;
        prev_row = new_row;
        new_row = nullptr;
    }
    prev_row = nullptr;
}

template <typename T>
void PointerMap<T>::construct_row (int cols, PointerMapNode<T>* n) {
    auto iter = n;
    PointerMapNode<T>* prev = nullptr;
    while (cols > 0) {
        iter->r = new PointerMapNode<T>();
        iter->u = nullptr;
        iter->d = nullptr;
        iter->l = prev;
        prev = iter;
        iter = iter->r;
        cols--;
    }
    iter->r = nullptr;
}
