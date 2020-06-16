class Node:
    def __init__(self, name):
        self.name=name
        self.neigh=[]
        self.vis=[]
    def __lt__(self, other):
        return self.name < other.name
        
class Solution:
    def visit(self,node,togo,ret):
        if togo==0: return True
        for i in range(len(node.neigh)):
            if node.vis[i]: continue
            node.vis[i]=True
            if self.visit(node.neigh[i],togo-1,ret):
                ret.append(node.neigh[i].name)
                #print('visit',node.name,togo,ret)
                return True
            node.vis[i]=False
        return False
    
    def findItinerary(self, tickets):
        HM={}
        for t in tickets:
            if t[0] not in HM:
                HM[t[0]]=Node(t[0])
            if t[1] not in HM:
                HM[t[1]]=Node(t[1])
            HM[t[0]].neigh.append(HM[t[1]])
            HM[t[0]].vis.append(False)
        
        for k,v in HM.items():
            v.neigh=sorted(v.neigh)
        
        node=HM['JFK']
        ret=[]
        self.visit(node, len(tickets), ret)
        ret.append('JFK')
        ret.reverse()
        return ret
        
