# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def visit(self, p, q):
        if p is None and q is None:
            return True
        if p is not None and q is not None:
            if p.val == q.val:
                left_eq=self.visit(p.left, q.left)
                right_eq=self.visit(p.right, q.right)
                if left_eq and right_eq:
                    return True
        return False
    
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        return self.visit(p,q)
