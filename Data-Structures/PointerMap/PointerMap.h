#pragma once

#include <iostream>
#include <vector>

template <typename T>
struct PointerMapNode {
    T datum;
    PointerMapNode<T>* u;
    PointerMapNode<T>* r;
    PointerMapNode<T>* d;
    PointerMapNode<T>* l;

    PointerMapNode ();

    PointerMapNode (T t);
};

template <typename T>
class PointerMap {
    private:
        PointerMapNode<T>* origin;

        int map_width;
        int map_height;

    public:
        PointerMap (int w, int h);

        void construct_row (int cols, PointerMapNode<T>* n);
};