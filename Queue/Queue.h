#ifndef _QUEUE_
#define _QUEUE_
#include "Node.h"
#include <iostream>

class Queue{
    Node *front;
    Node *back;
public:
    Queue();
    void enqueue(int);
    void dequeue();
    int peek();
    int size();
    bool isEmpty();
    void printque();
    ~Queue();
};
#endif