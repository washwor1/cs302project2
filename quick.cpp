// quick.cpp

#include "volsort.h"

#include <iostream>

// Prototypes

Node *qsort(Node *head, bool numeric);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {
    l.head=qsort(l.head,numeric);
}

Node *qsort(Node *head, bool numeric) {
    Node *left,*right;
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    partition(head,head,left,right, numeric);
    left = qsort(left,numeric);
    right = qsort(right,numeric);
    return concatenate(left,right);
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
    if (numeric) {
        for (Node * curr = pivot->next; curr != NULL; curr = curr->next) {
            if (1) {
                
            }
        }
    }
    
}

Node *concatenate(Node *left, Node *right) {
    while(left->next!=nullptr) {

    }
}

