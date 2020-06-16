from sortedcontainers import SortedList
class MedianFinder:

    def __init__(self):
        self.arr=SortedList()        

    def addNum(self, num: int) -> None:
        self.arr.add(num)

    def findMedian(self) -> float:
        N=len(self.arr)
        if N==0: return None
        if N%2==0: return 0.5*(self.arr[N//2]+self.arr[N//2-1])
        else: return self.arr[N//2]


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
