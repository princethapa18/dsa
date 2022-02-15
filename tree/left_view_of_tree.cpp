// { Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

vector<int> leftView(struct Node *root);

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
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
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void printTree(Node* root)
{
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);
    std::cout << "\n---- print Tree root->data : " << root->data << " ------ \n";
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
    std::cout << "\n---- print Tree end ----\n";
}

int main() {
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        printTree(root);
        if(root->left)
            printTree(root->left);
        if(root->right)
            printTree(root->right);
        vector<int> vec = leftView(root);
        cout << "------ tree left view-------\n";
        for(int x : vec)
            cout<<x<<" ";
        cout << endl;
    }
    return 0;
}

/*
./a.out 
1
1 3 2 4 5 6 7 N N N N N 8

              1
            /   \
           3      2
          / \    / \
         4  5   6   7
                 \ 
                  8
---- print Tree root->data ----1
1 
3 2 
4 5 6 7 
8 
---- print Tree ----

---- print Tree root->data ----3
3 
4 5 
---- print Tree ----

---- print Tree root->data ----2
2 
6 7 
8 
---- print Tree ----
------ tree left view-------
1 3 4 8 

*/

// } Driver Code Ends


/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   // go left if it contains both the child
   // 
   if(!root) return vector<int>();
   
   vector<int> res;
   Node * itr = root;
    
   
   queue<Node*> q;
   q.push(root);
   q.push(nullptr);
   res.push_back(root->data);
   // Breadth First traversal
   // add null after each line
   while(q.size() > 1)
   {
       Node *tmp = q.front();
       if(!tmp)
       {
           q.pop();
           tmp = q.front();
           res.push_back(tmp->data);
           q.push(nullptr);
       }
       if(tmp->left) q.push(tmp->left);
       if(tmp->right) q.push(tmp->right);
       q.pop();
   }
   
   
   return res;
}
