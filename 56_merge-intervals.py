from operator import itemgetter
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        A=intervals
        A.sort(key=itemgetter(0))
        N=len(A)
        if N==0: return []
        f=0
        i=0
        c=0
        while f<N:
            cb=A[c][0]
            ce=A[c][1]
            f=c
            while True:
                f+=1
                if f==N: break
                if A[f][0] <= ce:
                    ce=max(ce,A[f][1])
                else:
                    break
            c=f
            A[i][0]=cb
            A[i][1]=ce
            i+=1
        return A[0:i]
