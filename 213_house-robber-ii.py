class Solution:
    def rob(self, nums: List[int]) -> int:
        N=len(nums)
        if N==0: return 0
        if N==1: return nums[0]
        if N==2: return max(nums)
        
        T=[0]*N
        for i in range(N-2,-1,-1):
            cand=0
            if i+2<=N-2:
                cand=T[i+2]
            if i+3<=N-2:
                cand=max(cand,T[i+3])
            T[i]=nums[i]+cand
        mx0=max(T[0],T[1])


        T=[0]*N
        for i in range(N-1,0,-1):
            cand=0
            if i+2<=N-1:
                cand=T[i+2]
            if i+3<=N-1:
                cand=max(cand,T[i+3])
            T[i]=nums[i]+cand
        mx1=max(T[1],T[2])

        return max(mx0,mx1)
