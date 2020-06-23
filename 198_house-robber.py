from collections import deque
class Solution:
    def rob(self, nums: List[int]) -> int:
        N=len(nums)
        if N==0: return 0
        if N==1: return nums[0]
        if N==2: return max(nums[0], nums[1])
        if N==3: return max(nums[0]+nums[2], nums[1])
        T=deque()
        T.append(nums[0])
        T.append(nums[1])
        T.append(nums[2]+T[0])
        for i in range(3,N):
            T.append(nums[i]+max(T[-2],T[-3]))
            T.popleft()
        return max(T)
        
