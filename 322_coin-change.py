class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0: return 0
        C=set(coins)
        if len(C)==0 and 0 in C: return -1

        T=[0]*(amount+1)
        for c in C:
            if c<=amount:
                T[c]=1
        for i in range(1,len(T)):
            t=T[i]
            if t == 0:
                cnd=float('inf')
                for c in C:
                    idx = i-c
                    if i-c>=0:
                        cnd = min(cnd, T[idx]+1)
                T[i]=cnd
        ret =  T[-1]    
        if ret==0:
            return -1
        if ret==float('inf'):
            return -1
        return ret
