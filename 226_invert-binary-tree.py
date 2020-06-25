# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def foo(self, node: TreeNode):
      if node is None: return
      tmp = node.left
      node.left=node.right
      node.right=tmp
      self.foo(node.left)
      self.foo(node.right)
    def invertTree(self, root: TreeNode) -> TreeNode:
      self.foo(root)
      return root
