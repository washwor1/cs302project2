// qsort.cpp

#include "volsort.h"

#include <cstdlib>
#include <vector>
#include <iostream>


void qsort_sort(List &l, bool numeric) {
    std::vector<Node*> list;
    for (Node * curr = l.head; curr != NULL; curr = curr->next) {
        list.push_back(curr);
    }
    if (numeric == true)
    {
        qsort(*list.begin(), list.size(), sizeof(Node*),q_number_compare);
    }
    else
    {
        qsort(*list.begin(), list.size(), sizeof(Node*),q_string_compare);
    }
}

