class Solution:
    def minKBitFlips(self, A, K: int) -> int:
        N=len(A)
        cnt=0
        Q=deque()
        h=0
        qtop=None
        for i in range(N):
            if Q and i==Q[-1]:
                h=h ^ 1
                Q.pop()
            if A[i]==h:
                cnt+=1
                h=h^1
                if i+K>N: return -1
                Q.appendleft(i+K)
        return cnt
