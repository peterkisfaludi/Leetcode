class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        N=len(nums)
        
        maj = nums[0]
        cnt = 1
        for i in range(1, N):
            n=nums[i]
            if n==maj:
                cnt+=1
            else:
                cnt-=1
                if cnt==-1:
                    maj=n
                    cnt=1
        return maj
