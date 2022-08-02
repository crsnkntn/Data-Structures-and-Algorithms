#include <iostream>

#include "Data-Structures/Stack/Stack.h"
#include "Data-Structures/Stack/Stack.cpp"


int main () {
    Stack<int> s;
    s.push(99);
    s.push(99);
    s.push(96);
    s.push(96);
    s.push(97);
    s.push(97);
    s.push(93);
    s.push(93);
    s.push(92);
    s.push(92);

    s.print_stack(std::cout);

    return 1;
}