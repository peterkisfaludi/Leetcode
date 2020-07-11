# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def foo(self, n):
        if n is None: return 0
        l = self.foo(n.left)
        r = self.foo(n.right)
        mx=max(l,r)+1
        sm=l+r+1
        self.sm=max(self.sm,sm)
        return mx
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        if root is None: return 0
        self.sm=0
        self.foo(root)
        return self.sm - 1
