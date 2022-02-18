#pragma once
#include <string>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val) : data{val}, left{nullptr}, right{nullptr}  { }
    ~Node(){}
};

struct Tree
{
    Node *m_root{nullptr};
    ~Tree();
    Node* deleteRecursivePostOrder(Node *root);
    Node* buildTree(string str);
    void  printTree(Node* root);
    void  printTree();
};
