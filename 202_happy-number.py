class Solution:
    def ss(self,n):
        ret=0
        while n!=0:
            d=n%10
            ret+=d*d
            n=n//10
        return ret
    def isHappy(self, n: int) -> bool:
        v=set()
        while True:
            if n == 1: return True
            if n in v: return False
            v.add(n)
            n=self.ss(n)
