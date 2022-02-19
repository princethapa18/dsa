/* 19 Feb 2022 */

#include <iostream>
#include <string>
#include "iterative-tree-traversals.cpp"
#include <memory>

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