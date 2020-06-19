import math
class Solution:
    def numSquares(self, n: int) -> int:
        Q=set()
        Q.add(n)
        V=set()
        cnt=0
        while Q:
            Q2=set()
            #print(cnt,Q,V)
            for x in Q:
                if x==0: return cnt
                for i in range(1,math.floor(math.sqrt(x))+1):
                    num=x-i*i
                    if num not in V:
                        Q2.add(num)
                        V.add(num)
            Q=Q2
            cnt+=1
