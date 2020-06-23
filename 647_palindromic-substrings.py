class Solution:
    def expand(self, i, j, s) -> int:
        cnt=0
        while i>=0 and j<len(s):
            if s[i]!=s[j]:break
            i-=1;j+=1; cnt+=1
        return cnt
    
    def countSubstrings(self, s: str) -> int:
        N=len(s)
        if N==0: return 0
        if N==1: return 1
        acc=0
        for i in range(0,len(s)):
            acc+=self.expand(i,i,s)
            acc+=self.expand(i,i+1,s)
        return acc
