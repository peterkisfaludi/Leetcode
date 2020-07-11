# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        s=head
        f=head
        if head is None: return None        
        while True:
            f=f.next
            if f is None: return None
            if f==s: break
            s=s.next
            f=f.next
            if f is None: return None
            if f==s: break
        v=set()
        p=head
        while p is not None:
            if p in v: return p
            v.add(p)
            p=p.next
            
            
            
