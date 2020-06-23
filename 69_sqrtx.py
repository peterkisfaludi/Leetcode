class Solution:
    def fun(self,x,n):
        return x*x-n
    def fprime(self,x):
        return 2*x
    def mySqrt(self, x: int) -> int:
        if x==0: return 0
        n=x
        x=n/2
        for i in range(20):
            x=x-self.fun(x,n)/self.fprime(x)
        return int(x)
