# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def foo(self, t1, t2):
        if t1 is None and t2 is None: return None
        if t1 is None and t2 is not None: return t2            
        if t1 is not None and t2 is None: return t1
        r = TreeNode(t1.val+t2.val)
        r.left = self.foo(t1.left, t2.left)
        r.right = self.foo(t1.right,t2.right)        
        return r
        
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        if t1 is None and t2 is None: return None        
        if t1 is None and t2 is not None: return t2            
        if t1 is not None and t2 is None: return t1
        r=TreeNode(t1.val+t2.val)
        r.left = self.foo(t1.left, t2.left)
        r.right = self.foo(t1.right,t2.right)
        return r
