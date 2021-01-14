#include"CircularLinkedList.h"

CircularList::CircularList(){
    this->root = NULL;
}

void CircularList::push(int item){
    Node *newNode = new Node(item);
    Node *iter = root;
    if(root == NULL){
        root = newNode;
        newNode->next = newNode;
        return;
    }
    //find tail
     while(iter->next != root){
        iter = iter->next;
    }
    newNode->next = root;
    root = newNode;
    iter->next = root;
}

void CircularList::print(){
    Node *iter = root;
    if(root == NULL){
        std::cout << "List is Empty";
    }
    std::cout << iter->data << " ";
    while(iter->next != root){
        std::cout << iter->next->data << " ";
        iter = iter->next;
    }
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
    if(getSize() == 1){
        delete root;
        root = NULL;
        return;
    }
    while(iter->next != root){
        iter = iter->next;
    }
    iter->next = root->next;
    delete root;
    root = iter->next;
}

int CircularList::getSize(){
    Node *iter = root;
    if(root == NULL){
        return 0;
    }
    int count = 1;
    while(iter->next != root){
        iter = iter->next;
        count++;
    }
    return count;
}

CircularList::~CircularList(){
    Node *iter = root;
    while(iter->next != root){
        root = root->next;
        delete iter;
        iter = root;
    }
    
}