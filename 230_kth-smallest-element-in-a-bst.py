# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
        
    def visit(self, node, k, ap):        
        if node is None:
            return 0
        self.visit(node.left, k, ap)        
        self.retlist.append(node.val)
        self.visit(node.right, k, ap)
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        self.retlist=[]
        self.visit(root,k, 0)
        return self.retlist[k-1]
