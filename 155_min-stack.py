from sortedcontainers import SortedList
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.arr = []
        self.sa  = SortedList()

    def push(self, x: int) -> None:
        self.arr.append(x)
        self.sa.add(x)

    def pop(self) -> None:
        val = self.arr[-1]
        self.sa.remove(val)
        del self.arr[-1]

    def top(self) -> int:
        return self.arr[-1]

    def getMin(self) -> int:
        return self.sa[0]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
