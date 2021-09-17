// quick.cpp

#include "volsort.h"

#include <iostream>
#include <vector>
using namespace std;
// Prototypes

Node *qsort(Node *head, bool numeric);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {
    l.head=qsort(l.head,numeric);
}

Node *qsort(Node *head, bool numeric) {
    Node *left=nullptr,*right=nullptr;
    if(head!=nullptr){
        cout <<"\n\nhead: " <<head->number;
    }
    if ((head == nullptr) || head->next == nullptr) {
        return head;
    }
    partition(head,head,left,right, numeric);
    for (Node * curr = right; curr != NULL; curr = curr->next) {
        cout << "\n\n" << curr->number << ' ';
    }
    for (Node * curr = left; curr != NULL; curr = curr->next) {
        cout << "\n\n" << curr->number << ' ';
    }
    
    left = qsort(left,numeric);
    right = qsort(right,numeric);
    head->next=nullptr;
    left = concatenate(left,head);
    return concatenate(left,right);
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
    Node *curr = pivot->next;
    Node *currRight = nullptr,*currLeft =nullptr;
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
                    currRight = currRight->next;
                    if (curr->next==nullptr){
                        break;
                    }
                    curr = curr->next;
                }
            }
            else {
                if (left == nullptr) {
                    left = curr;
                    currLeft = left;
                    if (curr->next==nullptr){
                        break;
                    }
                    curr = curr->next;
                }
                else{
                    currLeft->next = curr;
                    currLeft = currLeft->next;
                    if (curr->next==nullptr){
                        break;
                    }
                    curr = curr->next;
                }
            }
        }
        if(left != nullptr) {
            left->next = nullptr;
        }
        if(right != nullptr){
            currRight->next = nullptr;
        } 
    }
}

Node *concatenate(Node *left, Node *right) {
    Node *currLeft =nullptr;
    currLeft=left;
    if (left == nullptr) {
        return right;
    }
    while(currLeft->next!=nullptr) {
        currLeft = currLeft->next;
    }
    currLeft->next=right;
    return left;
}

