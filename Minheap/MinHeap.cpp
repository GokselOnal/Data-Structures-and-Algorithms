#include "MinHeap.h"
#include <iostream>

MinHeap::MinHeap(int capacity){
    this->capacity = capacity;
    this->heap = new int[capacity + 1]; //starts from index 1
    this->size = 0;
}

void MinHeap::insert(int item){
    if(size >= capacity){
        std::cout << "Capacity is Full!" << std::endl;
        return;
    }
    int currentSize = size + 1;
    heap[currentSize] = item;
    percolateUp(size);
    size++;
}

void MinHeap::deleteMin(){
    if(size < 1){
        std::cout<<"Empty Heap" <<std::endl;
        return;
    }
    heap[1] = heap[size];
    percolateDown(1);
    size--;
}

int MinHeap::getMin(){
    if(size < 1){
        std::cout<<"Empty Heap" <<std::endl;
        return -1;
    }
    return heap[1];
}

void MinHeap::percolateUp(int hole){
    hole++;
    for(; hole > 1 && heap[hole/2] > heap[hole]; hole /=2){
        int temp = heap[hole];
        heap[hole] = heap[hole/2];
        heap[hole/2] = temp;
    }
}

void MinHeap::percolateDown(int hole){
    int child,tmp;
    tmp = heap[hole];

    if(hole *2 >size){
        return;
    }
    for(; hole * 2 <= size; hole = child){
        child = hole * 2;
        if(child != size && heap[child +1] < heap[child]){
            child++;
        }
        if(heap[child] < tmp){
            int temp = heap[child];
            heap[child] = heap[hole];
            heap[hole] = temp;
        }else{
            break;
        }
    }
}

MinHeap::~MinHeap(){
    delete[] this->heap;
}
