// quick.cpp
//jay ashworth and andy zeng


#include "volsort.h"

#include <iostream>
#include <vector>
using namespace std;
// Prototypes

Node *qsort(Node *head, bool numeric);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// Implementations

//wrapper function for qsort. same function as wrapper for merge.
void quick_sort(List &l, bool numeric) {
    l.head=qsort(l.head,numeric);
}


//similar driver function to merge with the exception of adding the pivot before merging the whole thing
Node *qsort(Node *head, bool numeric) {
    Node *left=nullptr,*right=nullptr;
    if ((head == nullptr) || head->next == nullptr) {
        return head;
    }
    partition(head,head,left,right, numeric);
    left = qsort(left,numeric);
    right = qsort(right,numeric);
    head->next=nullptr;
    left = concatenate(left,head);
    return concatenate(left,right);
}


//partition function. After checking for numeric, the function loops to iterate through the node string starting at head and calculates whether curr node is greater or lesser.
//If it is lesser, the node is put into left and if it is greater, it is put into right. I also implemented section after the loop that makes the final pointer in each node string
//equal to nullptr 
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
            currLeft->next = nullptr;
        }
        if(right != nullptr){
            currRight->next = nullptr;
        } 
    }
    else {
        while(curr!=nullptr){
            if(curr->string.compare(pivot->string) >= 0) {
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
            currLeft->next = nullptr;
        }
        if(right != nullptr){
            currRight->next = nullptr;
        } 
    }
}

//iterates through left until it reaches a null. Then adds right as the next node in left and returns left as the head of the newly combined Node string.
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

