"""
Week 01  06 Jan 2022
Reverse a singly linked list 

"""
import sys 
# for taking arguments


class Solution:
    #Function to reverse a linked list.
    # time complexity  O(n) 
    # space complexity O(1)
    
    # using stack  ---> time complexity  O(n) 
    #              ---> space complexity O(n)
    
    def reverseList(self, head):
        print("running reverseList function")
        if(head is None or (head is not None and head.next is None) ):
            return head
        reversed_list_head = head
        todo_list_head = head.next
        
        reversed_list_head.next = None
        
        while(todo_list_head is not None):
            # remember the next element of the todo_list_head
            next = todo_list_head.next
            # remove the head of the todo_list_head and put it behind the reversed_list_head
            todo_list_head.next = reversed_list_head
            # update the reversed_list_head
            reversed_list_head = todo_list_head
            # update the todo_list_head
            todo_list_head = next
        return reversed_list_head
        
#{ 
#  Driver Code Starts
# Node Class    
class Node:
    def __init__(self, val):
        self.data = val
        self.next = None

# Linked List Class
class Linked_List:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert(self, val):
        if self.head is None:
            self.head = Node(val)
            self.tail = self.head
        else:
            self.tail.next = Node(val)
            self.tail = self.tail.next
    def delete(self, val):
        print("\nRunning delete function")
        if(self.head is None ) : 
            print("Linked List is empty\n")
        if self.head and self.head.next is None:
            if self.head.data == val:
                self.head = None
                return
            else :
                print(val, " is not in the linked list\n")
       
        cur = self.head 
        print("cur.data ", cur.data)
        # if cur.data == val :    this condition doesnt work because it doesnt know the type of cur.data and val
        if int(cur.data) == int(val):    # now it casts both cur.data and val to int then checks the value
            print(val, "found and deleted")    # here no problem 
            self.head = cur.next
            cur = None
            return

        prev = cur
        cur = cur.next
        while cur is not None:
            print("in While loop")
            print("cur.data ", cur.data)
            if int(cur.data) == int(val):
                print(val, "found and deleted")    # here no problem 
                prev.next = cur.next
                cur = None
                return
            prev = cur
            cur = cur.next
        print(val, "not found in the linked list\n")


def printList(head):
    tmp = head
    while tmp:
        print(tmp.data, end=' ')
        tmp=tmp.next
    print()

def printHello():
    print("Hello")

printHello()

def main():
    print("running main function\n")
    # total arguments
    n = len(sys.argv)
    print("Total arguments passed: ", n)
    # Arguments passed
    print("\nName of Python script:", sys.argv[0])
    # python test.py arg1 arg2 
    # sys.argv  ---> list of cmd line arguments
    # len(sys.argv) --> No. of cmd line arguments
    # sys.argv[0]  --> name of the program i.e test.py
    ll = Linked_List() 
    
    for i in range (1, n):
        ll.insert(sys.argv[i])
    print ("Original: ", end="")
    printList(ll.head)
    
    sln = Solution()
    # list_head = sln.reverseList(list_head)
    # this gave error UnboundLocalError: local variable 'list_head' referenced before assignment
    ll.head  = sln.reverseList(ll.head)
    print("After Reverse: ", end="")
    printList(ll.head)

    ll.delete(7)
    printList(ll.head)

# Using the special variable 
# __name__
if __name__=="__main__":
    main()

# It start executing from the top
# First calls printHello() 
# then calls main()
# If this is what is happenning then whats the use of main in python ? Do we need and if yes then when ???
        
# } Driver Code Ends