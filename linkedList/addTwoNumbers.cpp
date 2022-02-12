/*  Add Two Numbers     Medium
    https://leetcode.com/problems/add-two-numbers/
    You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. 
    Add the two numbers and return the sum as a linked list.
    You may assume the two numbers do not contain any leading zero, except the number 0 itself.
    Committed on Week 01 07 Jan 2022
    Solved in 2019

    Input: l1 = [2,4,3], l2 = [5,6,4]
    Output: [7,0,8]
    Explanation: 342 + 465 = 807.

    Example 2:

    Input: l1 = [0], l2 = [0]
    Output: [0]

    Example 3:

    Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
    Output: [8,9,9,9,0,0,0,1]


*/

#include <iostream>
#include <typeinfo>
#include "linkedList.cpp"

using namespace std;

  
class Solution {
public:
    ListNode<int>* addTwoNumbers(ListNode<int>* l1, ListNode<int>* l2) {
        
        int carry = 0, num = 0;        
        //ListNode<int> *itr1 = l1, *itr2 = l2, *itr = NULL;
        //ListNode<int> *head = NULL;

        auto *itr1 = l1; // auto can deduce the type as ListNode<int>*
        auto *itr2 = l2;
        std::cout << "typeid(itr1).name " << typeid(itr1).name() << std::endl;
        std::cout << "typeid(itr2).name " << typeid(itr2).name() << std::endl;
        //auto *itr{nullptr}; // this gives this error unable to deduce ‘std::initializer_list<_Tp>*’ from ‘{nullptr}’
        //auto *head{nullptr};
        ListNode<int> *itr = nullptr;
        ListNode<int> *head = nullptr;
        
        
        while(itr1 && itr2)
        {
            num = itr1->val + itr2->val + carry;
            if(num >= 10)
            {
                num   = num % 10; 
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            
            if(!head)
            {
                head = new ListNode<int>(num);
                head->next = NULL;
                itr = head;
            }
            else
            {
                ListNode<int> *cur = NULL; 
                cur = new ListNode<int>(num);
                itr->next = cur;
                itr = cur;
            }
            
            itr1 = itr1->next;
            itr2 = itr2->next;
        }
        
        while(itr1)
        {
            num = itr1->val + carry;
            if(num >= 10)
            {
                num = num % 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            
            ListNode<int> *cur = NULL; 
            cur = new ListNode<int>(num);
            itr->next = cur;
            itr = cur;
            
            itr1 = itr1->next;
        }
        
        while(itr2)
        {
            num = itr2->val + carry;
            if(num >= 10)
            {
                num = num % 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            
            ListNode<int> *cur = NULL; 
            cur = new ListNode<int>(num);
            itr->next = cur;
            itr = cur;
            
            itr2 = itr2->next;
        }
          
        if(carry > 0)
        {
            ListNode<int> *cur = NULL; 
            cur = new ListNode<int>(carry);
            itr->next = cur;
        }
        
        return head;
    }
};

int main()
{
    //Input: l1 = [2,4,3], l2 = [5,6,4]
    //Output: [7,0,8]
    //Explanation: 342 + 465 = 807.
    
    LinkedList<int> l1, l2;
    l1.push_back(2);
    l1.push_back(4);
    l1.push_back(3);

    l2.push_back(5);
    l2.push_back(6);
    l2.push_back(4);

    Solution obj;
    ListNode<int> *newlist = obj.addTwoNumbers(l1.getHead(), l2.getHead());
    printList(newlist);

    return 0;
}