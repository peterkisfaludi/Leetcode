# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def v(self, node, st):        
        if node is None: return              
        #print('v',node.val,'st',st)
        nv=st+node.val
        if nv==self.sm: self.cnt+=1
        self.v(node.left, nv)
        self.v(node.right, nv)
        if node in self.vis: return
        self.vis.add(node)
        self.v(node.left, 0)
        self.v(node.right, 0)

    def pathSum(self, root: TreeNode, sum: int) -> int:
        self.sm=sum
        self.cnt=0        
        self.vis=set()
        self.v(root,0)
        
        
        return self.cnt
        
