#ifndef BST_H
#define BST_H

#include <vector>
#include "node.h"

class BinarySearchTree 
{ 
    Node * root;
public:
    BinarySearchTree();
    BinarySearchTree(int rootValue);
    Node * getRoot();
    Node * insert(Node* currentNode, int val);
    void insertBST(int val);
    bool Delete(Node* currentNode,int value);
    bool deleteBST(int value); 
    void inOrderPrint(Node * currentNode);
    void buildBST(const std::vector<int>& vec);
    void printBST() { printBST(root); }
    void printBST(Node* root);
};

#endif
