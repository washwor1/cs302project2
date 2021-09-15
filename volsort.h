// volsort.h

#ifndef VOLSORT_H
#define VOLSORT_H

#include <string>

struct Node {
    std::string string;
    int         number;
    Node       *next;
};

struct List {
    Node       *head;
    size_t      size;

    List(); 					// define in list.cpp
    ~List();					// define in list.cpp

    void push_front(const std::string &s);	//define below
};


// Functions -------------------------------------------------------------------

bool node_number_compare(const Node *a, const Node *b) {
  return a->number<b->number;
} 	//implement in this file (volsort.h), used by quick, merge and stl
bool node_string_compare(const Node *a, const Node *b){
  return a->string<b->string;
}		//implement in this file (volsort.h), used by quick, merge and stl

int q_number_compare(const void *a, const void *b){
  return (*(int*)a - *(int*)b);
}
int q_string_compare(const void *a, const void *b){
  return (*(int*)a - *(int*)b);
}


void dump_node(Node *n);					// implement in this file (volsort.h) to make it easier for TAs to grade

void stl_sort(List &l, bool numeric);	// define in stl.cpp - sort using std::sort
void qsort_sort(List &l, bool numeric);	// define in qsort.cpp - sort using qsort from cstdlib
void merge_sort(List &l, bool numeric);	// define in merge.cpp - your implementation
void quick_sort(List &l, bool numeric);	// define in quick.cpp - your implementation


#endif
