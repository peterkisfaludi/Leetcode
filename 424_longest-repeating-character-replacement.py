from collections import Counter
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        mx=1
        w=1
        C=Counter()
        N=len(s)
        if N<=1: return N
        T=0;H=0
        C[s[0]]=1
        while True:
            cont=False
            for c in C.keys():
                if C[c]+k>=w:
                    cont=True;break
            if cont:
                mx=max(mx,w)
                T+=1
                if T==N: return mx
                w+=1
                C[s[T]]+=1
                continue
            C[s[H]]-=1
            w-=1
            H+=1
        return mx        
