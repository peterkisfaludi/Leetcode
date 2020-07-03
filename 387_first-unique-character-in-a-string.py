from collections import Counter
class Solution:
    def firstUniqChar(self, s: str) -> int:
        cnt=Counter(s)
        N=len(s)
        for i in range(N):
            c=s[i]
            if cnt[c]==1: return i
        return -1
