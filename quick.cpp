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
    l.head=qsort(l.head,numeric);
}

Node *qsort(Node *head, bool numeric) {
    Node *left,*right;
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    partition(head,head,left,right, numeric);
    for (Node * curr = left; curr != NULL; curr = curr->next) {
        std::cout << left->number << std::endl;
    }
    
    left = qsort(left,numeric);
    right = qsort(right,numeric);
    head->next=nullptr;
    left = concatenate(left,head);
    return concatenate(left,right);
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
    Node *curr = pivot->next;
    Node *currRight,*currLeft;
    if (numeric) {
        while(curr!=nullptr){
            if(curr->number>=pivot->number) {
                if (right == nullptr) {
                    right = curr;
                    currRight = right;
                    if (curr->next==nullptr){
                        break;
                    }
                    curr = curr->next;
                }
                else{
                    currRight->next = curr;
                    currRight = right->next;
                    if (curr->next==nullptr)
                        break;
                    curr = curr->next;
                }
            }
            else if(curr->number<pivot->number) {
                if (left == nullptr) {
                    left = curr;
                    currLeft = left;
                    if (curr->next==nullptr)
                        break;
                    curr = curr->next;
                }
                else{
                    currLeft->next = curr;
                    currLeft = left->next;
                    if (curr->next==nullptr)
                        break;
                    curr = curr->next;
                }
            }
        }
        if(left != nullptr) {
            currLeft->next = nullptr;
        }
        if(right != nullptr){
            currRight->next = nullptr;
        }
        
    }
    std::cout << currLeft << " " << currRight << std::endl;
}

Node *concatenate(Node *left, Node *right) {
    if (left == nullptr) {
        return right;
    }
    while(left->next!=nullptr) {
        left = left->next;
    }
    left->next=right;
    return left;
}

