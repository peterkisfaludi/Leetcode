from typing import List
class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        N=len(nums)
        if N==0: return []
        ret=[0]*N
        ret[0]=nums[0]
        for i in range(1, N):
            ret[i]=ret[i-1]+nums[i]
        return ret
