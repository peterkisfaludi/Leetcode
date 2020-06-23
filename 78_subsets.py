class Solution:
    def foo(self,idx,stuff):
        if idx==self.N: self.ret.append(stuff); return
        self.foo(idx+1,stuff.copy())
        stuff.append(self.A[idx])
        self.foo(idx+1,stuff.copy())
        
    def subsets(self, nums):
        self.A=nums
        self.N=len(nums)
        self.ret=[]
        self.foo(0,[])
        return self.ret
