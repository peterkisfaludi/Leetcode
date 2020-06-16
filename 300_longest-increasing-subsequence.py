class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        N=len(nums)
        if N==0: return 0
        if N==1: return 1
        T=[0]*N
        T[0]=1
        ret=1
        for i in range(1,N):
            Tmax=0
            for j in range(i-1,-1,-1):
                if nums[i]>nums[j]:
                    Tmax=max(Tmax,T[j])
            T[i]=Tmax+1
            ret=max(T[i],ret)
        return ret
