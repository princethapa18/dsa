#pragma once
#include <string>
#include "node.h"

class Tree
{
public:
    Node *m_root{nullptr};
    ~Tree();
    Node* deleteRecursivePostOrder(Node *root);
    Node* buildTree(std::string str);
    void  printTree(Node* root);
    void  printTree();
};
