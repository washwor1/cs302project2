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

//wrapper function. all it does is assign the final list to the head of the original list.
void merge_sort(List &l, bool numeric) {
    l.head = msort(l.head, numeric);
}

//recursive function to drive the split and merge functions
//works by first finding the base case of 1 or 0 items in the list. Then if it fails the base case, it continues to split the list into halves using split() and calls itself on both new lists created by the split.
//when the function finally reaches the bottom of its recursion, it will start merging from the bottom up. you are then left with the sorted list which is returned as the result of the merge of the highest level msort().
Node *msort(Node *head, bool numeric) {
    Node *left,*right;
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    split(head,left,right);
    msort(left,numeric);
    msort(right,numeric);
    return merge(left,right,numeric);
}

//function uses the slow and fast pointer trick as told in the lab writeup to determine the midpoint in the list. it then assigns the new bounds and adds a nullptr to end of the left list so it has bounds in later function calls.
void split(Node *head, Node *&left, Node *&right) {
    Node *fast,*slow;
    slow = head;
    fast = head->next;
    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    left = head;
    right = slow->next;
    slow->next = nullptr;
}

//function works by setting the first and lowest value as the head and then uses "curr" as an iterator to add the next highest node until both are nullptr
//basically the same for number and string except string uses string::compare
Node *merge(Node *left, Node *right, bool numeric) {
    Node *head,*curr;
    if(numeric) {
        if (left->number>=right->number) {
            head=right;
            right=right->next;
        }
        else {
            head = left;
            left = left->next;
        }
        curr = head;
        while(left!=nullptr && right!= nullptr) {
            if (left == nullptr) {
                curr->next=right;
                right=right->next;
            }
            else if(right==nullptr||left->number<=right->number) {
                curr->next=left;
                right=right->next;
            }
            else{
                curr->next=right;
                right=right->next;
            }
            curr=curr->next;
        }
    }
    else {
        if (left->string.compare(right->string)>0) {
            head=right;
            right=right->next;
        }
        else {
            head = left;
            left = left->next;
        }
        while(left!=nullptr && right!= nullptr) {
            if(right==nullptr||left->string.compare(right->string)<0) {
                curr->next=left;
                left = left->next;
            }
            else{
                curr->next=right;
                right=right->next;
            }
            curr=curr->next;
        }
    }
    curr->next=nullptr;
    for (Node * curr2 = head; curr2 != NULL; curr2 = curr2->next) {
        cout << curr2->number << ' ';
    }
    cout << '\n';
    return head;
}

