// stl.cpp
//jay ashworth and andy zeng


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

//most basic sort function. it intakes the linked list into a vector by implementing a for loop similar to that in main and then passes that into stl::sort. 
//I then returned the sorted vector to the linked list by applying the same ideas used in the first for loop but in a more traditional for loop. 
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
    for (unsigned int i = 1; i<list.size();i++) {
        curr->next = list.at(i);
        curr = curr->next;
    }
}
