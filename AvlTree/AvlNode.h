#ifndef _AVLNODE_
#define _AVLNODE_
#include <iostream>

class AvlNode{
public:
    AvlNode(int);
    int data;
    AvlNode *left;
    AvlNode *right;
};
#endif