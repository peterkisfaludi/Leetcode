class Solution:
    def sp(self, node, cost):
        if cost >= self.SPC[node]:
            return
        self.SPC[node]=min(self.SPC[node], cost)
        for n,c in self.NEIGH[node]:
            self.sp(n,cost+c)
            
    def mpm(self, prev, act):
        mx=-float('inf')
        if act in self.vis:
            return self.SPC[prev]
        self.vis.add(act)
        if len(self.NEIGH[act])==0:
            return self.SPC[act]
        for n,_ in self.NEIGH[act]:
            mx=max(mx,self.mpm(act,n))
        return mx
        
    def networkDelayTime(self, times, N: int, K: int) -> int:
        NEIGH={}
        SPC={}
        for t in times:
            if t[0] not in NEIGH:
                NEIGH[t[0]]=set()
            if t[1] not in NEIGH:
                NEIGH[t[1]]=set()
            NEIGH[t[0]].add((t[1],t[2]))
        self.NEIGH=NEIGH
        
        #phase1
        for k in NEIGH.keys():
            SPC[k]=float('inf')
        self.SPC=SPC
        self.sp(K,0)
        #print(SPC)
        
        #phase2
        self.vis=set()
        ret = self.mpm(None, K)
        #print(self.vis)
        if len(self.vis) == N:
            return ret
        return -1
 
        
