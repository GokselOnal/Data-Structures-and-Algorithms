#ifndef _STACK_
#define _STACK_
#include"Node.h"
#include<iostream>

class Stack{
    Node* front;
public:
    Stack();
    void push(int);
    Node* top();
    void pop();
    void print();
    bool isEmpty();
    void makeEmpty();
    ~Stack();
};

#endif