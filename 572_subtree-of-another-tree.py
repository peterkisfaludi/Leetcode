# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.was_match=False
    def isMatch(self, s, t):
        if s is None and t is None: return True
        if s is None and t is not None: return False
        if s is not None and t is None: return False
        return s.val == t.val and self.isMatch(s.left, t.left) and self.isMatch(s.right,t.right)
    def visit(self, node, t):
        if node is None: return
        if node.val==t.val:
            self.was_match = self.was_match or self.isMatch(node,t)
        if not self.was_match:
            self.visit(node.left, t)
            self.visit(node.right, t)
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        self.was_match=False
        self.visit(s,t)
        return self.was_match
