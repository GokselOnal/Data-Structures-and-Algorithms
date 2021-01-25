#ifndef _NODEBTS_
#define _NODEBTS_
#include <iostream>

class NodeBst{
public:
    NodeBst(int);
    NodeBst *left;
    NodeBst *right;
    int data;
};
#endif