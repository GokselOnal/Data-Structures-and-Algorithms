#include"DoublyLinkedList.h"

DoublyList::DoublyList(){
    this->head = NULL;
}

void DoublyList::print(){
    NodeDoubly *iter = head;
    if(head == NULL){
        std::cout<<"Empty List" << std::endl;
        return;
    }
    while(iter != NULL){
        std::cout << iter->data << " ";
        iter = iter->next;
    }
    std::cout << std::endl;
}

void DoublyList::append(int item){
    NodeDoubly *newNode = new NodeDoubly(item);
    NodeDoubly *iter = head;
    if(head == NULL){
        head = newNode;
        return;
    }
    while(iter->next != NULL){
        iter = iter->next;
    }
    iter->next = newNode;
    newNode->prev = iter;
}
                        //index
void DoublyList::remove(int idx){
    NodeDoubly *iter = head;
    if(head == NULL){
        std::cout<<"Empty List" << std::endl;
        return;
    }
    if(idx > size() - 1){
        std::cout<<"Incorrect index" << std::endl;
        return;
    }
    else{
        if(idx == 0){
            head = head->next;
            delete iter;
            iter = head;
            return;
        }else{
            while(idx-1 > 0){
            iter = iter->next;
            idx--;
            }
            NodeDoubly *temp = iter->next;
            iter->next = temp->next;
            if(iter->next != NULL){
                temp->next->prev = iter;
                delete temp;
                return;
            }
            delete temp;
        }
    }  
}

int DoublyList::size(){
    int size = 0;
    NodeDoubly *iter = head;
    if(head == NULL){
        return -1;
    }
    else{
        while(iter != NULL){
            size++;
            iter = iter->next;
        }
        return size;
    }
}

DoublyList::~DoublyList(){
    NodeDoubly *iter = head;
    while(iter != NULL){
        head = iter->next;
        delete iter;
        iter = head;
    }
}