#include "Queue.h"

Queue::Queue(){
    this->front = NULL;
    this->back = NULL;
}

void Queue::enqueue(int item){
    Node *newNode = new Node(item);
    if(front == NULL){
        front = newNode;
        back = newNode;
        return;
    }
    back->next = newNode;
    back = newNode;
}

void Queue::dequeue(){
    Node *iter = front;
    if(front == NULL){
        std::cout <<"Queue is Empty" << std::endl;
        return;
    }
    front = iter->next;
    if(front == NULL){
        back == NULL;
    }
    delete iter;
}

int Queue::peek(){
    if(front == NULL){
        std::cout <<"Queue is Empty" << std::endl;
        return -1;
    }
    return front->data;
}

int Queue::size(){
    Node *iter = front;
    int size = 0;
    while(iter != NULL){
        size++;
        iter = iter->next;
    }
    return size;
}

bool Queue::isEmpty(){
    return front == NULL;
}

void Queue::printque(){
    Node *iter = front;
    while(iter != NULL){
        std::cout << iter->data << " ";
        iter = iter->next;
    }
    std::cout << std::endl;
}

Queue::~Queue(){
    Node *iter = front;
    while(iter != NULL){
        front = front->next;
        delete iter;
        iter = front;
    }
}