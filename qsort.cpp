// qsort.cpp

#include "volsort.h"

#include <cstdlib>
#include <vector>
#include <iostream>

int q_compare_number(const Node *a, const Node *b){
  if(a->number<b->number) {
      return -1;
  }
  else if (a->number==b->number) {
      return 0;
  }
  else {
      return 1;
  }
} // allows for qsort to work for numbers


void qsort_sort(List &l, bool numeric) {
    std::vector<Node*> list;
    for (Node * curr = l.head; curr != NULL; curr = curr->next) {
        list.push_back(curr);
    }
    if (numeric == true)
    {
        qsort(*list.begin(), list.size(), sizeof(Node*),q_compare);
    }
    else
    {
        qsort(*list.begin(), list.size(), sizeof(Node*),q_compare);
    }
    list.push_back(nullptr);
    l.head = list.at(0);
    Node * curr = l.head;
    for (int i = 1; i<list.size();i++) {
        curr->next = list.at(i);
        curr = curr->next;
    }
}

