class Solution:
    def dfs(self, a, c, seen):
        HM=self.HM
        if a in seen: return None
        seen.add(a)
        if a not in HM: return None
        if c not in HM: return None
        if a==c: return 1.0
        if c in HM[a]: return HM[a][c]
        
        for n in HM[a]:
            x=self.dfs(n,c,seen.copy())
            if x is not None:
                return HM[a][n]*x
    
    def calcEquation(self, equations, values, queries):
        HM={}
        E=len(equations)
        for di in range(E):
            d=equations[di]
            if d[0] not in HM:
                HM[d[0]]={}
            HM[d[0]][d[1]]=values[di]
            if d[1] not in HM:
                HM[d[1]]={}
            HM[d[1]][d[0]]=1/values[di]               
        #print (HM)
        self.HM=HM
        
        ret=[]
        for q in queries:
            x=self.dfs(q[0],q[1], set())
            if x is None:
                ret.append(-1.0)
            else: ret.append(x)
        return ret
        
