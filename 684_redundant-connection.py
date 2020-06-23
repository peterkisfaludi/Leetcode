class Solution:
    def fur(self, act, vis_set, vis_list):        
        for i in range(vis_list.index(act), len(vis_list)-1):
            tpl=(vis_list[i],vis_list[i+1])
            if tpl not in self.E:
                tpl=(vis_list[i+1],vis_list[i])
            mx=max(mx,self.E[tpl])
        
        self.ret=mx
        
    def findCircle(self, prev, act, vis_set, vis_list):
        if act in vis_set:
            self.fur(prev,act,vis_set,vis_list)
            return True
        vis_set.add(act)
        vis_list.append(act)
        
        for n in self.HM[act]:
            if n==prev: continue
            if self.findCircle(act,n,vis_set,vis_list):
                return True
        
        vis_list.pop()
        vis_set.discard(act)
        return False

    def findRedundantConnection(self, edges):
        
        HM={}
        E={}
        for i in range(len(edges)):
            e=edges[i]
            if e[0] not in HM: HM[e[0]]=set()
            if e[1] not in HM: HM[e[1]]=set()
            HM[e[0]].add(e[1])
            HM[e[1]].add(e[0])
            E[(e[0],e[1])]=i
            
        self.E=E
        self.HM=HM
        self.findCircle(None, edges[0][0],set(), [])
        #self.findCircle(None, 5,set(), [])
        
        return edges[self.ret]
