class Solution:
    def numDecodings(self, s: str) -> int:
        N=len(s)
        if N==0: return 0
        T=[0]*(N+1)
        T[N]=1
        if int(s[N-1])>0:
            T[N-1]=1
        else:
            T[N-1]=0
        for i in range(N-2,-1,-1):
            tmp=T[i+1]
            if int(s[i:i+2])<=26:
                tmp+=T[i+2]
            T[i]=tmp
            if int(s[i])==0:
                T[i]=0
        return T[0]
