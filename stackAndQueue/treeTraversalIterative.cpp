/* Week 1 02 Jan 2022
   Tree traversal iterative.
   Using stack 

*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Root -> Left -> Right
    vector<int> preorderTraversal(TreeNode* root) 
    {
        if(!root) return vector<int>();
        std::vector<int> ret;
        std::stack<TreeNode*> s;
        s.push(root);
        
        TreeNode* node = nullptr;
        
        while(!s.empty())
        {
            //visit
            node = s.top();
            s.pop();
            //
            ret.emplace_back(node->val); 
            if(node->right)
                s.push(node->right);
            if(node->left)
                s.push(node->left);
        }
             
        return ret;
    }

    // Left -> Right -> Root
    vector<int> postorderTraversal(TreeNode * root)
    {
        if(!root) return vector<int>();
        std::vector<int> ret;
        std::stack<TreeNode*> s;
        std::stack<int> out;

        TreeNode *node = nullptr;
        s.push(root);
        while(!s.empty())
        {
            node = s.top();
            s.pop();
            out.push(node->val);
            if(node->left)
                s.push(node->left);
            if(node->right)
                s.push(node->right);
        }

        while(!out.empty())
        {
            ret.emplace_back(out.top());
            out.pop();
        }

        return ret;
    }

    // Left -> Root -> Right
    vector<int> inorderTraversal(TreeNode * root)
    {
        if(!root) return vector<int>();
        std::vector<int> ret;
        std::stack<TreeNode*> s;

        TreeNode* node = root;

        while(!s.empty() || node)
        {
            if(node)
            {
                s.push(node);
                node = node->left;
            }
            else
            {
                //visit node
                node = s.top();
                s.pop();
                ret.emplace_back(node->val);
                node = node->right;
            }
        }

        return ret;
    }

};

template<typename T>
void printArray(std::vector<T>& vec)
{
    for(int i = 0; i < (int)vec.size(); i++)
        cout << vec[i] << " ";
}

/*
                            1
                          /   \
                         2      5
                        /  \   /
                       3   4   6
*/

int main()
{
    TreeNode *left = nullptr, *right = nullptr, 
             *root = nullptr;
    left  = new TreeNode{2};
    right = new TreeNode{5};
    root  = new TreeNode{1};

    root->left = left;
    root->right = right;

    left->left  = new TreeNode{3};
    left->right = new TreeNode{4};
    right->left = new TreeNode{6};

    Solution obj;
    std::vector<int> vec = obj.preorderTraversal(root);
    cout << "preorder traversal\n"; 
    printArray<int>(vec);
    vec = obj.postorderTraversal(root);
    cout << "\npostorder traversal\n"; 
    printArray<int>(vec);
    vec = obj.inorderTraversal(root);
    cout << "\ninorder traversal\n"; 
    printArray<int>(vec);

    return 0;
}