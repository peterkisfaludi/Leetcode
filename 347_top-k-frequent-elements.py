class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        D={}
        for x in set(nums):
          D[x]=nums.count(x)
        D_sort = sorted(D.items(), key=lambda kv: kv[1])
        D=D_sort
        ret = []
        for t in D:
          ret.append(t[0])
        return ret[-k:]
