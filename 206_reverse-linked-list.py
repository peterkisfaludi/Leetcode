# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head is None:
            return head
        if head.next is None:
            return head
        B=head
        F=head.next
        while True:
            T=F.next
            F.next=B
            if T is None:
                head.next=None
                head=F
                return head
            B=F
            F=T
            
        
            
