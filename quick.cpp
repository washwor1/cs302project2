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
    head->next=nullptr;
    left = concatenate(left,head);
    left = qsort(left,numeric);
    std::cout << left->number << std::endl;
    right = qsort(right,numeric);
    return concatenate(left,right);
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
    Node *curr = pivot->next;
    Node *currRight,*currLeft;
    int i = 0;
    if (numeric) {
        while(curr!=nullptr){
            if(curr->number>=pivot->number) {
                if (right == nullptr) {
                    right = curr;
                    if (curr->next==nullptr)
                        break;
                    curr = curr->next;
                }
                else{
                    right->next = curr;
                    right = right->next;
                    if (curr->next==nullptr)
                        break;
                    curr = curr->next;
                }
            }
            else if(curr->number<pivot->number) {
                if (left == nullptr) {
                    left = curr;
                    if (curr->next==nullptr)
                        break;
                    curr = curr->next;
                }
                else{
                    left->next = curr;
                    left = left->next;
                    if (curr->next==nullptr)
                        break;
                    curr = curr->next;
                }
            }
            i++;
        }
        if(left != nullptr) {
            currLeft->next = nullptr;
        }
        if(right != nullptr){
            currRight->next = nullptr;
        }
        
    }
    
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

