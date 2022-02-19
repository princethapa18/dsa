#include "bst.h"
#include "debugger.h"

#include <iostream>
#include <queue>

using namespace std;


BinarySearchTree::BinarySearchTree() :root{nullptr} {}

BinarySearchTree::BinarySearchTree(int rootValue) 
{
    root = new Node(rootValue);
}

Node * BinarySearchTree::getRoot() 
{
    return root;
}

Node * BinarySearchTree::insert(Node * currentNode, int val) 
{  
    if (currentNode == nullptr) 
    {
        return new Node(val);
    }
    else if (currentNode->data > val) 
    {
        currentNode->left = insert(currentNode -> left, val);
    } 
    else
    {
        currentNode->right = insert(currentNode -> right, val);
    }

    return currentNode;
}

void BinarySearchTree::insertBST(int value) 
{
    if (getRoot() == nullptr) 
    {
        root = new Node(value);
        return;
    }
    insert(this->getRoot(), value);
}

bool BinarySearchTree::Delete(Node * currentNode, int value) {

    if (root == nullptr) return false;

    Node *parent = nullptr; //To Store parent of currentNode
    while (currentNode != nullptr && (currentNode->data != value)) 
    {
        parent = currentNode;
        if (currentNode->data > value)
        currentNode = currentNode-> left;
        else
        currentNode = currentNode-> right;
    }

    if (currentNode == nullptr) return false;

    return false;
}

bool BinarySearchTree::deleteBST(int value) 
{
  return Delete(root, value);
}

void BinarySearchTree::inOrderPrint(Node * currentNode) 
{
  if (currentNode != nullptr) 
  {
    inOrderPrint(currentNode->left);
    cout << currentNode->data << endl;
    inOrderPrint(currentNode->right);
  }
}

void BinarySearchTree::buildBST(const std::vector<int>& vec)
{
    Debugger dbg{__FUNCTION__};
    for(auto &it : vec)
    {
        insertBST(it);
    }
}

void BinarySearchTree::printBST(Node* root)
{
    Debugger dbg{__FUNCTION__};
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);
    //std::cout << "\n---- root->data : " << root->data << " ------ \n";

    std::string str{"\n---- root->data : "};
    str += std::to_string(root->data) + " -----\n";
    dbg.printMessage(str);

    // BFS
    while(q.size() > 1)
    {
        Node *tmp = q.front();
        if(tmp == nullptr)
        {
            dbg.printMessage("\n");
            q.pop();
            tmp = q.front();
            q.push(nullptr);
        }
        //std::cout << tmp->data << " ";
        std::string tmpStr;
        tmpStr += std::to_string(tmp->data) + " ";
        dbg.printMessage(tmpStr);

        if (tmp->left)
        {
            q.push(tmp->left);
        }
        if(tmp->right)
        {
            q.push(tmp->right);
        }
        q.pop();
    }
}
