#ifndef _DOUBLYLIST_
#define _DOUBLYLIST_
#include <iostream>
#include "DoublyNode.h"

class DoublyList{
    NodeDoubly * head;
public:
    DoublyList();
    void print();
    void append(int);
    void remove(int);
    int size();
    ~DoublyList();
};
#endif