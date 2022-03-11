/* 11 Mar 2022  Hard  HeapTree 
   Merge K Sorted lists

*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    struct CompareValLesser 
    {
        bool operator()(const ListNode * p1, const ListNode * p2)
        {
            return (*p1).val < (*p2).val;
        }
    };

    struct CompareValGreater 
    {
        bool operator()(const ListNode * p1, const ListNode * p2)
        {
            return (*p1).val > (*p2).val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        ListNode *curr = nullptr, *head = nullptr, *temp = nullptr;    
        // priority_queue< T > maxHeap;  
        // priority_queue< ListNode* , vector<ListNode*>, greater<ListNode*>> minHeap; // min heap . By defaults its a max heap in stl
        // The compare function should be added based on val

        // priority_queue< ListNode* , vector<ListNode*>, CompareValLesser > maxHeap; // for custom type there should be a Custom comparation functor
        // Iam having issues with using lambda here.

        priority_queue< ListNode* , vector<ListNode*>, CompareValGreater > minHeap;
        
        for(auto &it : lists)
        {
            if(it)
            {
                minHeap.push( it );  // push the head to the minheap
            }
        }
        
        while(!minHeap.empty())
        {
            temp = minHeap.top();
            minHeap.pop();
                    
            if(!head)
            {
                head = temp;
                curr = head;
            }
            else
            {
               curr->next = temp;
               curr = curr->next;
            }
            
            if( temp->next )
            {
                minHeap.push(temp->next);
            }
        }
        
        return head;
    }    
};

ostream& operator << (ostream &os, ListNode *head)
{
    if(!head) return os;
    ListNode * curr = head;
    while(curr)
    {
        cout << curr->val << "->" ;
        curr = curr->next;
    }
    return os;
}

int main()
{
    // Solution sol;
    // vector<ListNode*> vec;
    // ListNode * res = sol.mergeKLists(vec);
    ListNode * t = new ListNode{4};
    ListNode * head = t;
    t->next = new ListNode(5);
    t = t->next; 
    t->next = new ListNode(7);

    cout << head;
    return 0;
}