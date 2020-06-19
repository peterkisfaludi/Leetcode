class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        if len(nums)==0: return 0
        T=[0]*(target+1)
        T[0]=1
        for i in range(1,target+1):
            tmp=0
            for n in nums:
                if i-n<0:continue
                tmp+=T[i-n]
            T[i]=tmp
        return T[-1]
