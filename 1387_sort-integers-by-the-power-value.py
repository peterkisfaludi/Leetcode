class Solution:
    def foo(self,num):
        D=self.D
        if num in D: return D[num]
        if num%2==0:
            retval = 1+self.foo(num//2)
            D[num] = retval
            return retval
        retval = 1+self.foo(num*3+1)
        D[num] = retval
        return retval
        
    def getKth(self, lo: int, hi: int, k: int) -> int:
        self.D={}
        self.D[1]=0
        for i in range(lo,hi+1):
            self.foo(i)
        
        cands=[]
        for i in range(lo,hi+1):
            cands.append((i,self.D[i]))
            
        #print(cands)
        srt = sorted(cands, key=lambda x: x[1])
        #print(srt)
        return srt[k-1][0]
