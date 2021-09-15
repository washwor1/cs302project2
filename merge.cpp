// merge.cpp

#include "volsort.h"

#include <iostream>
#include <vector>
using namespace std;

// Prototypes

Node *msort(Node *head, bool numeric);
void  split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool numeric);

// Implementations

void merge_sort(List &l, bool numeric) {
    if (l.size == 0 || l.size == 1) {
        return;
    }
    else if (l.size == 2) {
        if (l.head->number>l.head->next->number) {
            Node * curr = l.head;
            l.head=l.head->next;
            l.head->next=curr;
            l.head->next->next=nullptr;
        }
        return;
    }
    
}

Node *msort(Node *head, bool numeric) {
}

void split(Node *head, Node *&left, Node *&right) {
}

Node *merge(Node *left, Node *right, bool numeric) {
    Node *head,*curr;
    if(numeric) {
        if (left->number>=right->number) {
            head=right;
        }
        else {
            head = left;
        }
        curr = head;
        while(left->next!=nullptr && right->next!= nullptr) {
            if(right==nullptr||left->number<=right->number) {
                curr->next=left;
            }
            else{
                curr->next=right;
            }
            curr=curr->next;
        }
    }
    else {
        if (left->string.compare(right->string)>0) {
            head=right;
        }
        else {
            head = left;
        }
        while(left->next!=nullptr && right->next!= nullptr) {
            if(right==nullptr||left->string.compare(right->string)<0) {
                curr->next=left;
            }
            else{
                curr->next=right;
            }
            curr=curr->next;
        }
    }
    curr->next=nullptr;
    return head;
}

