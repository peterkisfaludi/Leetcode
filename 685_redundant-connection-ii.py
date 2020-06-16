class Solution:
    def fur(self, act, vis_set, vis_list):        
        actidx=vis_list.index(act)
        tpl=(vis_list[-1],act)
        mx=self.E[tpl]
        if self.cands:
            if mx in self.cands: self.ret=self.E[tpl]; return
        for i in range(actidx, len(vis_list)-1):
            tpl=(vis_list[i],vis_list[i+1])
            if self.E[tpl] in self.cands: self.ret=self.E[tpl];return
            mx=max(mx,self.E[tpl])        
        self.ret=mx
        
    def findCircle(self, act, vis_set, vis_list):
        if act in vis_set:
            self.fur(act,vis_set,vis_list)
            return True
        vis_set.add(act)
        vis_list.append(act)
        
        for n in self.HM[act]:
            if self.findCircle(n,vis_set,vis_list):
                return True
        
        vis_list.pop()
        vis_set.discard(act)
        return False

    def findRedundantDirectedConnection(self, edges):
        self.ret=None
        HM={}
        E={}
        P={}
        cands = set()
        for i in range(len(edges)):
            e=edges[i]
            if e[0] not in HM: HM[e[0]]=set()
            if e[1] not in HM: HM[e[1]]=set()
            HM[e[0]].add(e[1])
            E[(e[0],e[1])]=i
            if e[1] in P:
                #fight between e[0] and P[e[1]] (existing parent)
                cands.add(i)
                other = E[(P[e[1]],e[1])]
                cands.add( other )
                maxcand = max(i, other)
            P[e[1]]=e[0]
            
        self.E=E
        self.HM=HM
        #print(HM, cands)
        self.cands=cands
        
        if self.findCircle(edges[0][0],set(), []):
            return edges[self.ret]
        return edges[maxcand]
