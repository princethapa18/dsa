/* 19 Feb 2022*/

#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include "common.h"

#include "utilities/tree.h"
#include "utilities/bst.h"
#include "utilities/debugger.h"

using namespace std;

int main(int argc , char* argv[])
{ 
    if(argc < 2)
    {
        std::cout << "give argument 1 for binary tree and 2 for bst\n";
        return 0;
    }

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

        cout << "Press 1 for kth max value problem\n 2 for lowest common ancestor" << endl;
        int input;
        std::cin >> input;

        switch(input)
        {
        case 1:
            {
                int k;
                std::cout << "\nEnter k: ";
                std::cin >> k;
                std::cout << "\n" << k << "th max value: " << findKthMax(bst->getRoot(), k);
            }
            break;
        case 2:
            {
                int p, q;
                std::cout << "\nEnter p: ";
                std::cin >> p;
                std::cout << "\nEnter q: ";
                std::cin >> q;

                Node* ancestor = lowestCommonAncestor(bst->getRoot(), p, q);
                if(ancestor)
                    std::cout << "\n Lowest Common ancestor of " << p << " and " << q << " is " << ancestor->data;
            }
            break;
        default:
            break;
        }


    }
    return 0;
}


/* Lowest common ancestor
./Tree 2
Enter numbers to build a binary search tree: 6 2 8 0 4 7 9 N N 3 5

buildBST started...

buildBST ended!

printBST started...

---- root->data : 6 -----
6
2 8
0 4 7 9
printBST ended!
Press 1 for kth max value problem
 2 for lowest common ancestor
2

Enter p: 5

Enter q: 2

 Lowest Common ancestor of 5 and 2 is 2


*/



