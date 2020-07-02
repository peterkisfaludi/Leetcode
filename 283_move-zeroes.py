import typing
class Solution:
    def moveZeroes(self, nums) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        N=len(nums)
        if N==0: return nums
        if N==1: return nums
        i=0
        f=0
        while True:
            ni=nums[i]
            nf=nums[f]
            while ni != 0:
                i+=1
                if i==N: return nums
                ni=nums[i]
            f=i+1
            if f==N: return nums
            nf=nums[f]
            while nf == 0:
                f+=1
                if f==N: return nums
                nf=nums[f]
            #print(i,ni,f,nf)
            #swap
            tmp=nf
            nums[f]=nums[i]
            nums[i]=tmp
