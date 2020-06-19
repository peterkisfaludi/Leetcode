from collections import Counter
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        N=len(s2)
        k=len(s1)
        if k>N: return False        
        TG=Counter(s1)
        togo=len(TG.keys())
        #init
        for i in range(0,k-1):
            c=s2[i]
            if c in TG:
                TG[c]-=1
                if TG[c]==0:
                    togo-=1
        #loop
        for i in range(k-1,N):
            c=s2[i]
            if c in TG:
                TG[c]-=1
                if TG[c]==0:
                    togo-=1
                    if togo==0:
                        return True
            b=i-k+1
            c=s2[b]
            if c in TG:
                TG[c]+=1
                if TG[c]==1:
                    togo+=1
        return False
