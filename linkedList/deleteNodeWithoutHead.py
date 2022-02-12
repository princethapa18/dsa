"""
Week 01  07 Jan 2022
Delete a node from a singly linked list without a head

Ex:  3->4->5->6->1
Node pointing to 5 will be given
the singly linked list should look like this  3->4->6->1

Because we don't know the link to the previous node and also because its a singly linked list
There is only one solution
Move all the data contained in that node to the last

input will be like this 
    5->6->1->null         This is what we get
    If we delete 5 then the link will get broken

    the next pointer of the object 4 points to the pointer to the node containing data 5 
    Therefore we can't do any change in that pointer (meaning we can't alter the memory location of that pointer's pointee)
    Node 5 ----> [location 1234]
    Node to 4 -> next ---> (points to ) [location 1234]  
    Only thing we can do is move the next nodes 1 step up and then delete the last node

"""
import sys 
# for taking arguments

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

# Linked List Class
class Linked_List:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert(self, val):
        if self.head is None:
            self.head = ListNode(val)
            self.tail = self.head
        else:
            self.tail.next = ListNode(val)
            self.tail = self.tail.next
    def getNode(self, val):
        if self.head is None:
            print("Linked List is empty()");
        itr = self.head
        while itr is not None:
            if int(itr.val) == int(val):
                return itr
            itr = itr.next

        print(val, "not found in the linked list\n")
        return None


class Solution:
    def deleteNodeWithoutHead(self, node):
        if node is None :
            return 
        cur = node
        prev = None
        next = None
        while cur is not None and cur.next is not None:
            prev = cur    
            next = cur.next
            cur.val = next.val
            cur = next
            
        if prev is not None and cur is not None:
            prev.val = cur.val
            prev.next = None
            cur = None

def printList(head):
    tmp = head
    while tmp:
        print(tmp.val, end=' ')
        tmp=tmp.next
    print()

def main():
    print("running main function\n")
    # total arguments
    n = len(sys.argv)
    print("Total arguments passed: ", n)
    # Arguments passed
    print("\nName of Python script:", sys.argv[0])
    
    if n <= 1:
        print("Enter numbers for creating a linked list\n")

    ll = Linked_List() 
    
    for i in range (1, n):
        ll.insert(sys.argv[i])
    print ("Original: ", end="")
    printList(ll.head)
    
    sln = Solution()
    deleteNode = ll.getNode(5)
    sln.deleteNodeWithoutHead(deleteNode)
    print("After deletion: ", end="")
    printList(ll.head)

# Using the special variable 
# __name__
if __name__=="__main__":
    main()

