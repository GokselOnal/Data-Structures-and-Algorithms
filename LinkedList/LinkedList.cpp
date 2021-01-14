#include "Linkedlist.h"

LinkedList::LinkedList(){
    this->head = NULL;
}

void LinkedList::addNode(Node *newNode){
    Node *iter = head;
    if(first() == NULL){
        this->head = newNode;
        return;
    }
    while(iter->next != NULL){
        iter = iter->next;
    }
    iter->next = newNode;
}

void LinkedList::push(int item){
    Node *newNode = new Node(item);
    Node *temp = first();
    if(first() == NULL){
        head = newNode;
        return;
    }
    newNode->next = temp;
    head = newNode;
}
//after the given node, insert new item
void LinkedList::insert(Node *current, int item){
    Node *newItem = new Node(item);
    Node *iter = first();
    while(iter != NULL){
        if(iter == current){
            newItem->next = current->next;
            current->next = newItem;
            return;
        }
        iter = iter->next;
    }
    std::cout <<"Given node was not found" << std::endl;
}

void LinkedList::append(int item){
    Node *newItem = new Node(item);
    Node *iter = first();
    if(first() == NULL){
        head = newItem;
        return;
    }
    tail()->next = newItem;
}
//first input for item data, second for quantity
void LinkedList::append(int x, int y){
    for(int i = 0 ; i < y ; i++){
        append(x);
    }
}
//after the given node, remove that item
void LinkedList::remove(Node *current){
    Node *iter = first();
    if(first() == NULL){
        std::cout <<"List is empty" << std::endl;
        return;
    }
    while(iter != NULL){
        if(iter == current){
            Node *temp = current->next;
            current->next = temp->next;
            delete temp;
            return;
        }
        else{
            iter = iter -> next;
        }
    }
    std::cout <<"Given node was not found" << std::endl;
}
//returns the node with the given node data
Node *LinkedList::find(int item){    
    Node *iter = first();
    while(iter != NULL){
        if(iter->data == item){
            return iter;
        }
        else{
            iter = iter->next; 
        }
    }
    std::cout <<"Item was not found";
    return 0;
}
//returns the node at the given index
Node * LinkedList::findKth(int n){
    Node *iter = first();
    while(n > 0){
        if(iter != NULL){
            iter = iter->next;
        }
        else{
            std::cout <<"Stack Underflow" << std::endl;
            return 0;
        }
        n--;
    }
    return iter;
}

int LinkedList::getSize(){
    Node *iter = first();
    int count = 0;
    if(first() == NULL){
        return 0;
    }
    while(iter != NULL){
        iter = iter->next;
        count++;
    }
    return count;
}

void LinkedList::printList(){
    Node *iter = first();
    if(iter == NULL){
        std::cout <<"List is empty" << std::endl;
        return;
    }    
    while(iter != NULL){
        std::cout << iter->data << " ";
        iter = iter->next;
    }
    std::cout << std::endl;
}

LinkedList::~LinkedList(){
    Node* iter = head;
    while(iter != NULL){
        head = head->next;
        delete iter;
        iter = head;
    }
}

Node* LinkedList::first(){
    return head;
}

Node* LinkedList::tail(){
    Node *iter = first();
    while(iter->next != NULL){
        iter = iter->next;
    }
    return iter;
}