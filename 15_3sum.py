class Solution:
    def p1move(self,nums,N,p):
        v=nums[p]
        for i in range(p+1,N):
            if nums[i]!=v:
                return i
        return N
    def p2move(self,nums,N,p1,p2):
        v=nums[p2]
        for i in range(p2-1,p1,-1):
            if nums[i]!=v:
                return i
        return p1
    def bar(self,i,nums,N):        
        p1=i+1
        p2=N-1
        ret=[]
        t=-nums[i]
        while p1<p2:
            v1=nums[p1]
            v2=nums[p2]
            sm=v1+v2
            if sm>t:
                p2=self.p2move(nums,N,p1,p2)
            elif sm<t:
                p1=self.p1move(nums,N,p1)
            else:
                ret.append([v1,v2])
                p1=self.p1move(nums,N,p1)
                p2=self.p2move(nums,N,p1,p2)
        return ret

    def threeSum(self, nums: List[int]) -> List[List[int]]:
      N=len(nums)
      retval=[]
      if N<=2:
        return retval
      nums.sort()
      prev=None
      for i in range(0,N):
        x=nums[i]
        if prev is not None:
          if prev==x: continue
        prev=x
        ret=self.bar(i,nums,N)
        for j in range(0,len(ret)):
          ret[j].append(x)
          retval.append(ret[j])
      return retval
