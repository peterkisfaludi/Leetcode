class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root is None: return root
        Q=[root]        
        while True:
            if Q[0] is None: return root
            NQ=[]
            for i in range(0,len(Q)-1):
                Q[i].next=Q[i+1]
                NQ.extend([Q[i].left,Q[i].right])
            NQ.extend([Q[-1].left,Q[-1].right])
            Q=NQ
