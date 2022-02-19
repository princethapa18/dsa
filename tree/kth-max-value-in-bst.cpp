/* 19 Feb 2022
   Find kth maximum value in a binary search tree

*/
#include <iostream>
#include <stack>
#include <vector>
#include "utilities/bst.h"
#include "utilities/debugger.h"
using namespace std;


int findKthMax(Node* rootNode, int k) 
{
    if(!rootNode) return 0;
    int count = 0;
    std::stack<Node*> st;
    st.push(rootNode);
    Node* cur = rootNode;
    while(cur || !st.empty())
    {
        if(cur)
        {
            st.push(cur);
            cur = cur->right; //go right
        }
        else
        {
            cur = st.top();
            st.pop();
            count++;
            if(count == k) return cur->data;
            cur = cur->left;
        }
    }
    return 0;
}