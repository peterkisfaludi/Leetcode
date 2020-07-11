class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        sn = sorted(nums)
        #print(nums)
        #print(sn)
        n = len(nums)
        if n == 0: return 0
        if n == 1: return 0
        fne=None
        lne=None
        for i in range(n):
            if nums[i] != sn[i]:
                fne=i
                break
        for i in range(n-1,-1,-1):
            if nums[i] != sn[i]:
                lne=i
                break
        if lne is None:
            return 0
        return lne-fne+1
