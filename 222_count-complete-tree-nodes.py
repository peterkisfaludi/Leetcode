# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def visit(self, node):
        if node is None: return 0
        return 1+self.visit(node.left)+self.visit(node.right)
    def countNodes(self, root: TreeNode) -> int:
        return self.visit(root)
        
