#include <iostream>
#include <sstream>
#include <queue>
#include <vector>
#include "tree.h"
#include "debugger.cpp"

using namespace std;

Tree::~Tree()
{
    Debugger dbg{__FUNCTION__};
    deleteRecursivePostOrder(m_root);
}
Node* Tree::deleteRecursivePostOrder(Node *root)
{
    if(!root) return nullptr;
    if(root->left)  root->left  = deleteRecursivePostOrder(root->left);
    if(root->right) root->right = deleteRecursivePostOrder(root->left);
    delete root;
    return nullptr;
}

// Function to Build Tree
Node* Tree::buildTree(string str)
{
    Debugger dbg{__FUNCTION__};
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    m_root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(m_root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return m_root;
}

void Tree::printTree(Node* root)
{
    Debugger dbg{__FUNCTION__};
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);
    std::cout << "\n---- root->data : " << root->data << " ------ \n";
    // BFS
    while(q.size() > 1)
    {
        Node *tmp = q.front();
        if(tmp == nullptr)
        {
            std::cout << "\n";
            q.pop();
            tmp = q.front();
            q.push(nullptr);
        }
        std::cout << tmp->data << " ";

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

void Tree::printTree() 
{ 
    printTree(this->m_root);
}
