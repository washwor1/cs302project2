// qsort.cpp

#include "volsort.h"

#include <cstdlib>
#include <vector>
#include <iostream>


int q_compare_number(const void *a, const void *b){
  int l = ((struct Node *)a)->number;
  int r = ((struct Node *)b)->number; 
  return (l - r);
} // allows for qsort to work for numbers
int q_compare_string(const void *a, const void *b){
  std::string l = ((struct Node *)a)->string;
  std::string r = ((struct Node *)b)->string;
  return l.compare(r);
}


void qsort_sort(List &l, bool numeric) {
    std::vector<Node*> list;
    for (Node * curr = l.head; curr != NULL; curr = curr->next) {
        list.push_back(curr);
    }
    if (numeric == true)
    {
        qsort(*list.begin(), list.size(), sizeof(Node*),q_compare_number);
    }
    else
    {
        qsort(*list.begin(), list.size(), sizeof(Node*),q_compare_string);
    }

    for (int i = 0; i<list.size();i++) {
        std::cout<<list.at(i)->number;
    }
    std::cout << '\n';

    // list.push_back(nullptr);
    // l.head = list.at(0);
    // Node * curr = l.head;
    // for (int i = 1; i<list.size();i++) {
    //     curr->next = list.at(i);
    //     curr = curr->next;
    // }
}

