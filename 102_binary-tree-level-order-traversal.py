# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
      if root is None: return []
      idx=0
      Q=[[root],[]]
      ret = []
      while len(Q[idx])>0:
        other = (idx+1)%2
        ls = [x.val for x in Q[idx]]
        ret.append(ls)
        for node in Q[idx]:                    
          if node.left is not None:
            Q[other].append(node.left)
          if node.right is not None:
            Q[other].append(node.right)
        Q[idx]=[]
        idx=other

      return ret        
