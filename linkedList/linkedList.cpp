#include "linkedList.h"
#include <iostream>
#include <stdio.h>

template<typename T>
void LinkedList<T>::push_back(T val)
{
    ListNode<T> *node = new ListNode<T>(val);
    if(!head)
    {
        // head = std::unique_ptr<Node>(new Node{data, std::move(head)});
        // std::unique_ptr<B> p = std::make_unique<D>();
        head = tail = node;
    }
    else
    { 
        tail->next = node;
        tail = node;
    }
}

template<typename T>
void LinkedList<T>::pop_back()
{
    if(!head)
    {
        fprintf(stderr, "LinkedList empty\n");
        return;
    }
    
    if(head->next == nullptr)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }

    auto cur  = head->next;
    auto prev = head;

    while(cur)
    {
        if(cur->next == nullptr)
        {
            prev->next = nullptr;
            delete cur;
            tail = prev;
            return;
        }
        prev = cur;
        cur  = cur->next;
    }
}

template <typename T>
void printList(const ListNode<T> *head)
{
    if(!head)
    {
        fprintf(stderr, "list is empty. Can't print!!\n");
        return;
    }
    const ListNode<T> *cur = head;
    while(cur)
    {
        std::cout << cur->val << "->";
        cur = cur->next;
    } 
    std::cout << "\n";
}

// int main()
// {
//     LinkedList<int> ll;
//     ll.push_back(1);
//     ll.push_back(4);
//     ll.push_back(6);
//     ll.push_back(8);
//     printList(ll);
//     ll.pop_back();
//     printList(ll);
// }