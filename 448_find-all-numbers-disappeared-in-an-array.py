class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        N=len(nums)
        arr=[False]*N
        for x in nums:
            arr[x-1]=True
        ret=[]
        for i in range(N):
            if arr[i]==False:
                ret.append(i+1)
        return ret
