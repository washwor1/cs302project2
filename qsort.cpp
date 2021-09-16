// qsort.cpp

#include "volsort.h"
#include <string.h>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

int q_compare_number(const void *a, const void *b){
    Node *l = (Node *)a;
    Node *r = (Node *)b;
    cout << "number: " << ((Node *)a)->number << endl;
    cout << "number: " << ((Node *)b)->number << endl;
    cout << l->number << " " << endl;
    cout << r->number << " " << endl;
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
    Node *l = (Node *)a;
    Node *r = (Node *)b;
    return strcmp(l->string.c_str(), r->string.c_str());
}


void qsort_sort(List &l, bool numeric) {
    std::vector<Node*> list;
    for (Node * curr = l.head; curr != NULL; curr = curr->next) {
        list.push_back(curr);
    }
    if (numeric == true)
    {
        qsort(list.data(), list.size(), sizeof(Node*), q_compare_number);
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

