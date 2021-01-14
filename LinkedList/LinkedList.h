#ifndef _LINKEDLIST_
#define _LINKEDLIST_
#include "Node.h"
#include<iostream>

class LinkedList{
    Node *head;
    Node* first();
    Node* tail();
public:
    LinkedList();
    void addNode(Node*);
    void push(int);
    void insert(Node *,int);
    void append(int);
    void append(int,int);
    void remove(Node*);
    Node * find(int);
    Node * findKth(int);
    int getSize();
    void printList();
    ~LinkedList();
};

#endif