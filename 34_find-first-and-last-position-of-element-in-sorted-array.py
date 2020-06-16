class Solution:
    def searchRange(self, nums, target: int):
        A=nums
        t=target
        N=len(A)
        ret = [-1,-1]
        if N==0: return ret
        
        ci=N
        B=0
        E=N-1
        while True:
            M=(B+E)//2
            m=A[M]; e=A[E]; b=A[B]
            if t==e: ci=min(ci,E)
            if t==b: ci=min(ci,B)
            if t>m:
                if B==M: break
                B=M
            else:
                if t==m: ci=min(ci,M)
                if E==M: break
                E=M
        if ci != N:
            ret[0]=ci
        ci=-1
        B=0
        E=N-1
        while True:
            M=(B+E)//2
            m=A[M]; e=A[E]; b=A[B]
            if t==e: ci=max(ci,E)
            if t==b: ci=max(ci,B)
            if t>=m:
                if t==m: ci=max(ci,M)
                if B==M: break
                B=M
            else:
                if E==M: break
                E=M
        ret[1]=ci
        return ret
