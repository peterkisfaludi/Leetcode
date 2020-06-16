
from sortedcontainers import SortedList
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        N=len(nums)
        ret=[]
        if k==0:return ret
        if k==1:return nums
        if N==0: return ret
        w = SortedList(nums[0:k]) 
        for i in range(1,N-k+1): 
            ret.append(w[-1]) 
            #print('i {} w {} r {}'.format(i,w, ret)) 
            w.remove(nums[i-1]) 
            w.add(nums[i+k-1]) 
        ret.append(w[-1]) 
        return ret
