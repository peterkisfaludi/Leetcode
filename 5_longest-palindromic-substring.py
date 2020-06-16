class Solution:
    def expand(self, i: int, j: int, s: str) -> int:
        while i>=0 and j<len(s):
            if s[i]!=s[j]: break
            i-=1; j+=1
        return i,j
    def longestPalindrome(self, s: str) -> str:
        N=len(s)
        if N==0: return ""
        if N==1: return s
        mx=0
        ret=""
        for i in range(0,N):
            i1,j1=self.expand(i,i+1,s)
            m1=j1-i1-1
            i2,j2=self.expand(i,i,s)
            m2=j2-i2-1
            if m1 > mx:
                mx=m1
                ret=s[i1+1:j1]
            if m2 > mx:
                mx=m2
                ret=s[i2+1:j2]
        return ret
    
            
        
