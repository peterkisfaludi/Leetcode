from sortedcontainers import SortedList
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:        
        sl = SortedList()
        n=len(matrix)
        if n==0: return 0
        for r in matrix:
            for c in r:
                sl.add(c)
        return sl[k-1]
            
