from typing import List
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        N=len(nums)
        if N==0: return None
        dessum=N*(N+1)//2
        return dessum - sum(nums)
