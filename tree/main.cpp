/* 19 Feb 2022*/

#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include "iterative-tree-traversals.cpp"
#include "kth-max-value-in-bst.cpp"
using namespace std;

int main(int argc , char* argv[])
{ 
    if(argc < 2)
        return 0;

    string inputstr;
    if( stoi(argv[1]) == 1)
    {
        cout << "Enter numbers to build a tree: ";
        getline(cin, inputstr);
        std::unique_ptr<Tree> treePtr{new Tree};
        //auto p = make_unique<int[]>(5);
        //auto rp = std::unique_ptr<Resource, customDeleter>(new Resource, customDeleter());
        Tree *tree = treePtr.get();
        tree->buildTree(inputstr);
        tree->printTree();
        iterativeInorderTraversal(tree->m_root);
    }
    else
    {
        cout << "Enter numbers to build a binary search tree: ";
        getline(cin, inputstr);
        std::vector<int> inputvec;
        int num;
        std::stringstream ss{inputstr};
        while(ss >> num)
            inputvec.push_back(num);
        std::unique_ptr<BinarySearchTree> bstPtr{new BinarySearchTree};
        BinarySearchTree *bst = bstPtr.get();
        bst->buildBST(inputvec);
        bst->printBST();
        int k;
        std::cout << "\nEnter k: ";
        std::cin >> k;
        std::cout << "\n" << k << "th max value: " << findKthMax(bst->getRoot(), k); 
    }
    return 0;
}