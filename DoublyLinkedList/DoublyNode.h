#ifndef _NODEDOUBLY_
#define _NODEDOUBLY_
#include <iostream>

class NodeDoubly{
public:
    NodeDoubly(int);
    int data;
    NodeDoubly *next;
    NodeDoubly *prev;
};
#endif