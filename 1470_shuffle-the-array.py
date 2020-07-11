class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        if n==0: return nums
        nums[0] *= 10000
        for i in range(n):
            nums[i*2]+=(nums[i]%10000)*10000
        for j in range(n,2*n):
            nums[(j-n)*2+1]=(nums[j]%10000)
        for i in range(0,n*2,2):
            nums[i]//=10000
        return nums
