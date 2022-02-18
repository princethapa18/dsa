/* 18 Feb 2022
   Iterative tree traversals revision

*/
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <vector>
#include "utilities/tree.h"
#include "utilities/debugger.cpp"
#include <memory>
using namespace std;

/*

1 3 2 4 5 6 7 N N N N N 8

              1
            /   \
           3      2
          / \    / \
         4  5   6   7
                 \ 
                  8


1 2 N 3 4             ---> N means nullptr
           1
          / \
         2   N
        / \
       3   4

20 15 25 12 N 22 28
           20
          /  \
        15    25
        /    /  \
      12    22  28  

*/
void iterativeInorderTraversal(Node *root)
{
  Debugger dbg{__FUNCTION__};
  if(!root) return;

  stack<Node*> st;
  Node* curr = root;

  while(!st.empty() || curr!= nullptr)
  {
    while(curr != nullptr)
    {
      st.push(curr);
      curr = curr->left;
    }
    curr = st.top();
    st.pop();
    cout << curr->data << " ";
    curr = curr->right;
  }
}

int main()
{ 
    string inputstr;
    cout << "Enter numbers to build a tree: ";
    getline(cin, inputstr);
    std::unique_ptr<Tree> treePtr{new Tree};
    //auto p = make_unique<int[]>(5);
    //auto rp = std::unique_ptr<Resource, customDeleter>(new Resource, customDeleter());
    Tree *tree = treePtr.get();
    tree->buildTree(inputstr);
    tree->printTree();
    iterativeInorderTraversal(tree->m_root);
    return 0;
}


