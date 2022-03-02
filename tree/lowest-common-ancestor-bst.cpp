/* 2 Mar 2022
   Lowest Common Ancestor of a bst
   https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
   https://www.techiedelight.com/find-lowest-common-ancestor-lca-two-nodes-bst/

*/

#include "utilities/bst.h"
#include "utilities/debugger.h"

Node* lowestCommonAncestor(Node* root, int p, int q)
{
    if(!root) return nullptr;

    if(root->data > std::max(p, q))
        return lowestCommonAncestor(root->left, p, q); // both p and q in the left
    else if(root->data < std::min(p, q))
        return lowestCommonAncestor(root->right, p, q); // both p and q in the right

    return root; // p and q on either side of the root . so this is the parent.
}
