# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def visit(self, node, t, anc):
        if node is None:
            return
        anc.append(node.val)
        if node.val==t:
            return
        if t<node.val:
            self.visit(node.left,t,anc)
        else:
            self.visit(node.right,t,anc)
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root is None: return None
        a1=[]
        a2=[]
        self.visit(root,p.val,a1)
        self.visit(root,q.val,a2)
        for i in range(0,min(len(a1),len(a2))):
            if a1[i]!=a2[i]:
                return TreeNode(a1[i-1])
        return TreeNode(a1[i])
