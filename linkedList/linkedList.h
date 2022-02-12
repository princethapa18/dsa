#pragma once

template<typename T>
struct ListNode {
    T val;
    ListNode<T> *next; 
    ListNode(T x) : val(x), next{nullptr}  { }
 };
 
template<typename T> 
class LinkedList 
{
    ListNode<T> *head;
    ListNode<T> *tail;
public:
    LinkedList(): head{nullptr}, tail{nullptr}{}
    ~LinkedList()
    {
        ListNode<T> *itr = head, *next = nullptr;
        while(itr)
        {
            next = itr->next;
            itr->next = nullptr;
            delete itr;
            itr = next;
        }
    }
    ListNode<T>* getHead() { return head;}
    ListNode<T>* getTail() { return tail;}
    void push_back(T val); // O(1)  insert at the end
    void pop_back();       // O(1)  delete an element from the end
};

template <typename T>
void printList(const ListNode<T> *head);