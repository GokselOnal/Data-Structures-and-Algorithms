#include"CircularLinkedList.h"

CircularList::CircularList(){
    this->root = NULL;
}

void CircularList::push(int item){
    Node *newNode = new Node(item);
    Node *iter = root;
    if(root == NULL){
        root = newNode;
        newNode->next = root;
        return;
    }
    newNode->next = root;
    root = newNode;
    //find tail
     while(iter->next != root){
        iter = iter->next;
    }
    iter->next = root;
}

void CircularList::print(){
    Node *iter = root;
    if(root == NULL){
        std::cout << "List is Empty";
    }
    while(iter->next != root){
        std::cout << iter->data << " ";
        iter = iter->next;
    }
    std::cout << iter->data;
}

void CircularList::append(int item){
    Node *newNode = new Node(item);
    Node *iter = root;
    if(iter == NULL){
        newNode->next = newNode;
        root = newNode;
        return;
    }
    while(iter->next != root){
        iter = iter->next;
    }
    newNode->next = root;
    iter->next = newNode;
}

void CircularList::pop(){
    Node *iter = root;
    if(root == NULL){
        std::cout << "List is empty";
        return;
    }
    while(iter->next != root){
        iter = iter->next;
    }
    iter->next = root->next;
    delete root;
    root = iter->next;
}
