class Solution:
    def gardenNoAdj(self, N: int, paths):
        HM={}
        for i in range(N):
            HM[i]=set()
        F=[None]*N
        for e in paths:
            e0=e[0]-1
            e1=e[1]-1
            HM[e0].add(e1)
            HM[e1].add(e0)
        for i in range(N):
            cands=[True]*4
            for n in HM[i]:
                if F[n] is not None: cands[F[n]]=False
            flower=cands.index(True)
            F[i]=flower
        return [x+1 for x in F]
