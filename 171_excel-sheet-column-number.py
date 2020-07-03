class Solution:
    def char2val(self, s):
        return 1+ ord(s) - ord('A')

    def titleToNumber(self, s: str) -> int:
        N=len(s)
        if N==0: return 0
        posmul=1
        ret=0
        for i in range(N-1,-1,-1):
            x=self.char2val(s[i])*posmul
            ret+=x
            posmul*=26
        return ret
