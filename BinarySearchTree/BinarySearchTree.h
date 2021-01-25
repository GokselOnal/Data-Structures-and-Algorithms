#ifndef __BINARYSEARCHTREE__
#define __BINARYSEARCHTREE__
#include "NodeBst.h"
#include<iostream>

class BinarySearchTree{
    NodeBst *root;
    void insert(int,NodeBst*&);
    void remove(int,NodeBst*&);
    void printPreorder(NodeBst*);
    void printInorder(NodeBst*);
    void printPostorder(NodeBst*);
    void makeEmpty(NodeBst*&);
  
public:
    BinarySearchTree();
    void insert(int);
    void remove(int);
    void printPreorderTree();
    void printInorderTree();
    void printPostorderTree();
    NodeBst *findMin(NodeBst*);
    NodeBst *findMax(NodeBst*);
    ~BinarySearchTree();
};
#endif