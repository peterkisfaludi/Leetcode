class Solution:
    def wiggleSort(self, nums) -> None:
        n=len(nums)
        if n<=1: return
        tmp = sorted(nums)
        s=n//2
        b=n-1
        if n%2==0:
            s-=1
        for i in range(0,n,2):
            nums[i]=tmp[s]
            if i+1<=n-1:
                nums[i+1]=tmp[b]
            s-=1
            b-=1
        print(nums)
