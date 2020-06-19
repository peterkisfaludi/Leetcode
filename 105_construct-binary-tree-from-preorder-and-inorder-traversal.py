# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def foo(self, pre, ino):
        #print('pre {} ino {}'.format(pre,ino))
        if pre==[]: return None
        root_val=pre[0]
        root=TreeNode(root_val)
        
        ino_idx=ino.index(root_val)
        B=ino[0:ino_idx]
        D=[]
        if ino_idx+1<len(ino):
            D=ino[ino_idx+1:]
        
        A=pre[1:1+len(B)]
        C=[]
        if len(D)!=0:
            C=pre[-len(D):]
        
        #print('A {} B {} C {} D {}'.format(A,B,C,D))
        root.left=self.foo(A,B)
        root.right=self.foo(C,D)
        return root
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        return self.foo(preorder, inorder)
