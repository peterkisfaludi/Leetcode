class Node:
    def __init__(self):
        self.nxt=set()
        self.idx=None
        
class Solution:
    def visit(self, root, node, vis):
        if node.idx in vis: return True
        if root.idx==node.idx: return False
        vis.add(node.idx)
        ret=True
        for n in node.nxt:
            ret=ret and self.visit(root,n,vis)
        return ret
        
    def canFinish(self, numCourses: int, prerequisites) -> bool:
        HM={}
        for p in prerequisites:
            if p[0]==p[1]: return False
            if p[0]>=numCourses or p[1]>=numCourses: continue
            if p[0] not in HM:
                HM[p[0]]=Node()
                HM[p[0]].idx=p[0]
            if p[1] not in HM:
                HM[p[1]]=Node()
                HM[p[1]].idx=p[1]
            HM[p[0]].nxt.add(HM[p[1]])
            
        ret = True
        for k,v in HM.items():
            for n in v.nxt:
                ret = ret and self.visit(v, n, set())
        return ret
