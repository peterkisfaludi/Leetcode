class Solution:
    def sortColors(self, nums) -> None:
        N=len(nums)
        if N<=1: return
        Ri=0
        Bi=N-1
        i=0
        while i<=Bi:
            while nums[Ri]==0:
                Ri+=1
                if Ri==Bi: return
            i=max(i,Ri)
            while nums[Bi]==2:
                Bi-=1
                if Ri==Bi: return
            if nums[i]==0:
                nums[i]=nums[Ri]
                nums[Ri]=0
            elif nums[i]==2:
                nums[i]=nums[Bi]
                nums[Bi]=2
            else:
                i+=1
            #print(i,nums,Ri,Bi)
        #print(nums)
