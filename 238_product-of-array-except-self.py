class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        N=len(nums)
        if N==1: return [0]
        L=[1]*N
        R=[1]*N
        
        for i in range(1,N):
            L[i]=L[i-1]*nums[i-1]
        for i in range(N-2,-1,-1):
            R[i]=R[i+1]*nums[i+1]
        for i in range(0,N):
            nums[i]=L[i]*R[i]
        return nums
        
