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
    l.head = msort(l.head, numeric);
}

Node *msort(Node *head, bool numeric) {
    Node *left,*right;
}

void split(Node *head, Node *&left, Node *&right) {
    Node *fast,*slow;
    slow = head;
    fast = head->next;
    //uses the slow and fast pointer trick as told in the lab writeup
    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    left = head;
    slow->next = nullptr;
    right = slow->next;
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

