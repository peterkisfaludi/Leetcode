# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if head is None: return head
        eh=head.next
        if eh is None: return head
        n=head
        old=n
        while n is not None:
            old=n
            n=n.next
            if n is None:
                break
            old.next=n.next
            if n.next is None:
                break
            n.next=n.next.next
            n=old.next
        old.next=eh
        return head
