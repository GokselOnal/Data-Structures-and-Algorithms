#include"BinarySearchTree.h"


BinarySearchTree::BinarySearchTree(){
    this->root == NULL;
}

void BinarySearchTree::insert(int item, NodeBst * & tree){
    NodeBst *newNode = new NodeBst(item);
    if(tree == NULL){
        tree = newNode;
    }
    else if(tree->data < item){
        return insert(item,tree->right);
    }
    else if(tree->data > item){
        return insert(item,tree->left);
    }
}

void BinarySearchTree::insert(int item){
    insert(item,root);
}

void BinarySearchTree::remove(int item, NodeBst * & tree){
    NodeBst *temp;
    if(tree == NULL){
        return;
    }
    if(tree->data > item){
        remove(item, tree->left);
    }
    else if(tree->data < item){
        remove(item, tree->right);
    }
    else if(tree->left != NULL && tree->right != NULL){
        tree->data = findMin(tree->right)->data;
        remove(tree->data, tree->right);
    }
    else{
        NodeBst *old = tree;
        tree = ( tree->left != NULL) ? tree->left : tree->right;
        delete old;
    }
}

void BinarySearchTree::remove(int item){
    remove(item,root);
}

NodeBst *BinarySearchTree::findMin(NodeBst *tree){
    if(tree == NULL){
        std::cout << "Tree is Empty" << std::endl;
        NodeBst *empty = new NodeBst(-1);
        return empty;
    }
    if(tree->left == NULL){
        return tree;
    }
    return findMin(tree->left);
}

NodeBst *BinarySearchTree::findMax(NodeBst *tree){
    if(tree == NULL){
        std::cout << "Tree is Empty" << std::endl;
        NodeBst *empty = new NodeBst(-1);
        return empty;
    }
    if(tree->right == NULL){
        return tree;
    }
    return findMax(tree->right);
}

void BinarySearchTree::printPreorder(NodeBst *tree){
    if(tree == NULL){
        return;
    }
    std::cout << tree->data << " ";
    printPreorder(tree->left);
    printPreorder(tree->right);
}

void BinarySearchTree::printPreorderTree(){
    printPreorder(root);
}

void BinarySearchTree::printInorder(NodeBst *tree){
    if(tree == NULL){
        return;
    }
    printInorder(tree->left);
    std::cout << tree->data << " ";
    printInorder(tree->right);
}

void BinarySearchTree::printInorderTree(){
    printInorder(root);
}

void BinarySearchTree::printPostorder(NodeBst *tree){
    if(tree == NULL){
        return;
    }
    printPostorder(tree->left);
    printPostorder(tree->right);
    std::cout << tree->data << " ";
}

void BinarySearchTree::printPostorderTree(){
    printPostorder(root);
}

void BinarySearchTree::makeEmpty(NodeBst * & tree){
    if(tree == NULL){
        return;
    }
    else if(tree->left != NULL){
        makeEmpty(tree->right);
    }
    else if(tree->right != NULL){
        makeEmpty(tree->right);
    }
    delete tree;
}

BinarySearchTree::~BinarySearchTree(){
    makeEmpty(root);
}
