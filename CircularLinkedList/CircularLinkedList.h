#ifndef _CIRCLE_
#define _CIRCLE_
#include"Node.h"
#include<iostream>

class CircularList{
    Node* root;
public:
    CircularList();
    void push(int);
    void print();
    void append(int);
    void pop();
    ~CircularList();
};

#endif