class Solution:
    def countPrimes(self, n: int) -> int:
        if n==0: return 0
        if n==1: return 0
        if n==2: return 0
        if n==3: return 1

        nums = [True]*n
        nums[0]=False
        nums[1]=False
        for i in range(2,n):
            if nums[i]==True:
                k=2
                while i*k<n:
                    nums[i*k]=False
                    k+=1
        #print(nums)
        return nums.count(True)
