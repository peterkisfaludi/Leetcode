class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        N=len(nums)
        if N==0:return 0
        mn=N+1
        head=0
        tail=0
        sm=nums[0]
        while True:
            if sm < s:
                head+=1
                if head==N: 
                    if mn==N+1:
                        return 0
                    else:
                        return mn
                sm += nums[head]
            elif sm > s:
                mn=min(mn,head-tail+1)
                tail += 1
                if tail > head: return 1
                sm -= nums[tail-1]
            else: # sm == s
                mn=min(mn,head-tail+1)                
                head+=1
                if head==N: return mn
                sm += nums[head]
