class Solution:
    def __init__(self, nums: List[int]):
        self.A=nums
        self.G=set()
        for x in nums:
            self.G.add(x)
        self.reset()

    def reset(self) -> List[int]:
        self.R=self.G
        return self.A

    def shuffle(self) -> List[int]:
        tmp=[]
        while len(self.R)>0:
            val=random.choice(tuple(self.R))
            tmp.append(val)
            self.R.remove(val)
        self.reset()
        return tmp

# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
