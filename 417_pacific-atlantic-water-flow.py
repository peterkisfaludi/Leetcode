class Solution:
    def flow(self,m,r,c):
        if r<0 or r==self.R: return False
        if c<0 or c==self.C: return False
        if m[r][c] == 'V': return False
        if m[r][c]==True:
            return True
        m[r][c]='V'
        if ( r+1<self.R and self.matrix[r+1][c]<=self.matrix[r][c] and self.flow(m,r+1,c)) \
        or ( r-1>=0 and self.matrix[r-1][c]<=self.matrix[r][c] and self.flow(m,r-1,c)) \
        or ( c+1<self.C and self.matrix[r][c+1]<=self.matrix[r][c] and self.flow(m,r,c+1)) \
        or ( c-1>=0 and self.matrix[r][c-1]<=self.matrix[r][c] and self.flow(m,r,c-1)):
            m[r][c]=True
            return True
        m[r][c]=False
        return False
    
    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:
        R=len(matrix)
        if R==0: return []
        self.R=R
        C=len(matrix[0])
        if C==0: return []
        self.C=C
        self.matrix=matrix
        A=[None]*R
        for i in range(R):
            A[i]=[False]*C
        
        A[R-1]=[True]*C
        for r in range(R):
            A[r][C-1]=True
        
        for r in range(R-1):
            for c in range(C-1):
                self.flow(A,r,c)
        
        P=[None]*R
        for i in range(R):
            P[i]=[False]*C
    
        P[0]=[True]*C
        for r in range(R):
            P[r][0]=True

        for r in range(1,R):
            for c in range(1,C):
                self.flow(P,r,c)

        #print(A)
        #print(P)
        ret=[]
        for r in range(R):
            for c in range(C):
                if A[r][c] and P[r][c]:
                    ret.append([r,c])
        return ret
