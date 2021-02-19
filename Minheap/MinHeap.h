#ifndef __MINHEAP__
#define __MINHEAP__

class MinHeap{
    int *heap;//array
    int size;
    int capacity;
    void percolateDown(int);
    void percolateUp(int);
public:
    MinHeap(int);
    void insert(int);
    void deleteMin();
    int getMin();
    ~MinHeap();
};
#endif