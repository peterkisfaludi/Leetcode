"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if head is None: return None
        HM={}
        node=head
        while node is not None:
            new_node=Node(node.val)
            HM[node]=new_node
            node=node.next
        node=head
        while node is not None:
            new_node=HM[node]
            if node.next is not None:
                new_node.next=HM[node.next]
            if node.random is not None:
                new_node.random=HM[node.random]
            node=node.next
        return HM[head]
