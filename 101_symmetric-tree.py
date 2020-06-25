class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root is None:return True
        Q1, Q2=[root],[root]
        while Q1 or Q2:
            if len(Q1) != len(Q2): return False
            n=len(Q1)
            Q1_new = []
            Q2_new = []
            for i in range(n):
                if Q1[i] is None and Q2[i] is None: continue
                if Q1[i] is None or Q2[i] is None: return False
                if Q1[i].val != Q2[i].val: return False
                Q1_new.extend([Q1[i].left,Q1[i].right])
                Q2_new.extend([Q2[i].right,Q2[i].left])
            Q1=Q1_new
            Q2=Q2_new
        return True
