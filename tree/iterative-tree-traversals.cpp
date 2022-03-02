/* 18 Feb 2022
   Iterative tree traversals revision

*/
#include <iostream>
#include <stack>
#include <vector>

#include "common.h"

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
#include "utilities/tree.h"
#include "utilities/debugger.h"

void iterativeInorderTraversal(Node *root)
{
  Debugger dbg{__FUNCTION__};
  if(!root) return;

  stack<Node*> st;
  Node* curr = root;

  while(!st.empty() || curr!= nullptr)
  {
    if(curr)
    {
      st.push(curr);
      curr = curr->left;
    }
    else
    {
        curr = st.top();
        st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
  }
}



