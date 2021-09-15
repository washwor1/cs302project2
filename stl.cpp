// stl.cpp

#include "volsort.h"

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


bool node_number_compare(const Node *a, const Node *b) {
  return a->number<b->number;
} 	//implement in this file (volsort.h), used by quick, merge and stl
bool node_string_compare(const Node *a, const Node *b){
  return a->string<b->string;
}		//implement in this file (volsort.h), used by quick, merge and stl

void stl_sort(List &l, bool numeric) {
    vector<Node*> list;
    for (Node * curr = l.head; curr != NULL; curr = curr->next) {
        list.push_back(curr);
    }
    if(numeric) {
        sort(list.begin(),list.end(),node_number_compare);
    }
    else {
        sort(list.begin(),list.end(),node_string_compare);
    }
    list.push_back(nullptr);
    l.head = list.at(0);
    Node * curr = l.head;
    for (int i = 1; i<list.size();i++) {
        curr->next = list.at(i);
        curr = curr->next;
    }
}
