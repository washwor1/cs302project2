#include "volsort.h"


List::List() {
    head = nullptr;
    size = 0;
}

List::~List() {
    delete []head;
}
