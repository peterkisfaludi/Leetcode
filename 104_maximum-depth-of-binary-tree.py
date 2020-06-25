# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def foo(self, node):
        if node is None: return 0
        return 1 + max(self.foo(node.left), self.foo(node.right))
    def maxDepth(self, root: TreeNode) -> int:
        return self.foo(root)
