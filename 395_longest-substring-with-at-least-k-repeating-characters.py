from collections import Counter
class Solution:
    def foo(self, s) -> int:
        N=len(s)
        if N<self.k: return 0
        cnt=Counter(s)
        li=0
        allgood=True
        mx=0
        for i in range(N):
            if cnt[s[i]]<self.k:
                mx=max(mx,self.foo(s[li:i]))
                allgood=False
                li=i+1
        if not allgood:
            mx=max(mx,self.foo(s[li:]))
            #print('foo not all good',s,'return',mx)
            return mx
        #print('foo all good',s,'return',N)
        return N
        
    def longestSubstring(self, s: str, k: int) -> int:
        if k<=1: return len(s)
        self.k=k
        return self.foo(s)
