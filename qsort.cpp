// qsort.cpp
//jay ashworth and andy zeng


#include "volsort.h"
#include <string.h>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

//got help from ashley on piazza for these.
//comparison function that typecasts the void *s into a Node* and does the proper numerical comparisons.
int q_compare_number(const void *a, const void *b){
    Node *l = *(Node **)a;
    Node *r = *(Node **)b;
    if ((l->number) < (r->number))
    {
        return -1;
    }
    else if((l->number) > (r->number)){
        return 1;
    }
    else if((l->number) == (r->number)){
        return 0;
    }
} // allows for qsort to work for numbers
int q_compare_string(const void *a, const void *b){
    Node *l = *(Node **)a;
    Node *r = *(Node **)b;
    return strcmp(l->string.c_str(), r->string.c_str());
}

//very similar function to the one used in stl sort.
void qsort_sort(List &l, bool numeric) {
    std::vector<Node*> list;
    for (Node * curr = l.head; curr != NULL; curr = curr->next) {
        list.push_back(curr);
    }
    if (numeric == true)
    {
        qsort(list.data(), list.size(), sizeof(Node*), q_compare_number);
    }
    else{
        qsort(list.data(), list.size(), sizeof(Node*), q_compare_string);
    }

    // std::cout << '\n';
    // for (int i = 0; i<list.size();i++) {
    //     std::cout<<list.at(i)->number<<'\n';
    // }
    // std::cout << '\n';

    list.push_back(nullptr);
    l.head = list.at(0);
    Node * curr = l.head;
    for (unsigned int i = 1; i<list.size();i++) {
        curr->next = list.at(i);
        curr = curr->next;
    }
}

