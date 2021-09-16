// quick.cpp

#include "volsort.h"

#include <iostream>
#include <vector>

// Prototypes

Node *qsort(Node *head, bool numeric);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {
    std::vector<Node*> list;
    for (Node * curr = l.head; curr != NULL; curr = curr->next) {
        list.push_back(curr);
    }
    
}

Node *qsort(Node *head, bool numeric) {
    
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
   Node *pivot = right;
}

Node *concatenate(Node *left, Node *right) {

}

