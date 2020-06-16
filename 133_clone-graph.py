"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = []):
        self.val = val
        self.neighbors = neighbors
"""
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if node is None: return None
        Q=[node]
        HM={node.val: None}
        while len(Q)>0:
            n=Q[-1]
            del Q[-1]
            new_node=Node(n.val, [i.val for i in n.neighbors])
            HM[n.val]=new_node
            for nei in n.neighbors:                
                if nei.val in HM: continue
                HM[nei.val]=None
                Q.append(nei)                
        
        for k in HM:
            n=HM[k]
            for i in range(0,len(n.neighbors)):
                n.neighbors[i] = HM[n.neighbors[i]]
        
        
        return HM[node.val]
