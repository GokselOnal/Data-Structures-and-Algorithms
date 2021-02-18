#include"AvlTree.h"

AvlTree::AvlTree(){
    this->root = NULL;
}

int AvlTree::getHeight(AvlNode *node){
    if(node == NULL){
        return 0;
    } else{
        int l = getHeight(node->left);
        int r = getHeight(node->right);
        return max(l,r) +1;
    }
}

int AvlTree::max(int n1,int n2){
    if(n1 > n2){
        return n1;
    }else{
        return n2;
    }
}

int AvlTree::getDifference(AvlNode *node){
    return getHeight(node->left) - getHeight(node->right);
}

AvlNode* AvlTree::leftleftRotate(AvlNode *node){
    AvlNode * tmp = node->left;
    node->left = tmp->right;
    tmp->right = node;
    return tmp;
}

AvlNode* AvlTree::rightrightRotate(AvlNode *node){
    AvlNode *tmp = node->right;
    node->right = tmp->left;
    tmp->left = node;
    return tmp;
}