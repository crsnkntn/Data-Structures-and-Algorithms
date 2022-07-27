// Used to test each Data Structure 
#include "LinkedLists/LinkedList.h"
#include "LinkedLists/LinkedList.cpp"


int main () {
    LinkedList<int> ll;
    ll.append(1);
    ll.append(3);
    ll.append(6);
    ll.print_list_contents();
    ll.remove(3);
    ll.print_list_contents();
    return 1;
}