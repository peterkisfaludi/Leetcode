from sortedcontainers import SortedDict
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        D=SortedDict()
        T=[2,3,5]
        mn=None
        D[1]=[0,0,0]
        for _ in range(n):
            mn,val=D.popitem(index=0)
            for i in range(3):
                new_val=val
                new_val[i]+=1
                new_key=mn*T[i]
                D[new_key]=new_val
        return mn
     
