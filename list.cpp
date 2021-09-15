
#include "volsort.h"


List::List() {
    head = nullptr;
    size = 0;
}

//i wasnt exactly sure about the destructor for the linked list so i used code from stack overflow
//https://stackoverflow.com/questions/2265967/writing-a-linkedlist-destructor
List::~List() {
    Node* current = head;
    while( current != 0 ) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = 0;
}
