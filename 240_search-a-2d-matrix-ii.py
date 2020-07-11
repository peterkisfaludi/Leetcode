class Solution:
    def src(self, mx, t):
        n=len(matrix)
        if n==0: return False
        m=len(matrix[0])
        if m==0: return False
        
        mv = matrix[n//2][m//2]
        if mv==t: return True
        if mv<t:
            A=mx[0:n//2][0:m//2]
            return self.src(A) or self.src(B) or self.src(C)
        if mv>t:
            return self.src(A) or self.src(B) or self.src(C)
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        n=len(matrix)
        if n==0: return False
        m=len(matrix[0])
        if m==0: return False
        
        
        
