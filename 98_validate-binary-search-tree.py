# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBST(self, node):
        if node is None:
            return (None,None,True)
        
        left_max,left_min,left_is_bst = self.isBST(node.left)
        right_max,right_min,right_is_bst = self.isBST(node.right)
        
        mx=node.val
        if right_max is not None:
            mx=max(mx,right_max)        
        mn=node.val
        if left_min is not None:
            mn=min(mn,left_min)
            
        is_bst=left_is_bst and right_is_bst
        if left_max is not None:
            is_bst=is_bst and left_max < node.val
        if right_min is not None:
            is_bst=is_bst and right_min > node.val

        #print(node.val,mx,mn,is_bst)
        return (mx,mn,is_bst)
        
    def isValidBST(self, root: TreeNode) -> bool:
        _,_,ret = self.isBST(root)
        return ret
        
