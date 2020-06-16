class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m=len(matrix)
        if m==0: return
        n=len(matrix[0])
        if n==0: return
        
        R=set()
        C=set()
        
        for r in range(0,m):
            for c in range(0,n):
                if matrix[r][c]==0:
                    R.add(r)
                    C.add(c)
        
        for r in R:
            matrix[r]=[0]*n
        for c in C:
            for i in range(0,m):
                matrix[i][c]=0
        
