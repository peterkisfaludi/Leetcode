class Solution:

    def isBipartite(self, graph) -> bool:
        N=len(graph)
        if N<=2: return True
        NE=[None]*N
        V=[False]*N
        for x in range(N):
            NE[x]=set()
        for i in range(N):
            for no in graph[i]:
                NE[i].add(no)

        Q=set()
        P=set()
    
        for i in range(N):
            if V[i]==True: continue
            Q.add(i)
            while Q:
                Q2=set()
                for x in Q:
                    V[x]=True
                    for n in NE[x]:
                        if n in P: continue
                        if n in Q: return False
                        Q2.add(n)
                P=Q
                Q=Q2
        return True
