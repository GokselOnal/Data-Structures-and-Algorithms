#ifndef _AVLTREE_
#define _AVLTREE_
#include "AvlNode.h"
#include <iostream>

class AvlTree{
    AvlNode *root;
public:
    AvlTree();
    int getHeight(AvlNode*);
    int max(int,int);
    int getDifference(AvlNode*);
    AvlNode *leftleftRotate(AvlNode*);
    AvlNode *rightrightRotate(AvlNode*);
};
#endif