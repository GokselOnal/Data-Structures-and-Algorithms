#include"Stack.h"

Stack::Stack(){
    front = NULL;
}

void Stack::push(int item){
    Node *newNode = new Node(item);
    if(isEmpty()){
        front = newNode;
        return;
    }
    newNode->next = front;
    front = newNode;
}

void Stack::pop(){
    Node *temp = top();
    if(isEmpty()){
        std::cout << "Empty List";
        return;
    }
    front = temp->next;
    delete temp;
}

void Stack::print(){
    Node *iter = top();
    if(isEmpty()){
        std::cout << "Empty List";
        return;
    }
    while(iter != NULL){
        std::cout << iter->data << " "; 
        iter = iter->next;
    }
    std::cout << std::endl;
}

bool Stack::isEmpty(){
    return front == NULL;
}

void Stack::makeEmpty(){
    Node *iter = top();
    Node *temp = top();
    if(isEmpty()){
        std::cout << "Empty List";
        return;
    }
    while(iter != NULL){
        front = top()->next;
        delete temp;
        iter = front;
    }
}

Node* Stack::top(){
    return front;
}

Stack::~Stack(){
    makeEmpty();
}