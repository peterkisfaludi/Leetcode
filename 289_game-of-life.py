class Solution:
    def getCell(self,r,c):
        if r<0 or r>= self.R: return 0
        if c<0 or c>= self.C: return 0
        return self.A[r][c]
    def getSumNeigh(self,r,c):
        #get neighs
        acc=0
        for i in range(r-1,r+2):
            for j in range(c-1,c+2):
                if i==r and j==c: continue
                acc+=self.getCell(i,j)
        #print('sumN',r,c,acc)
        return acc        
    def gameOfLife(self, board) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        A=board
        B=[x[:] for x in board]
        self.A=A
        R=len(A)
        if R==0:return
        self.R=R
        C=len(A[0])
        if C==0:return
        self.C=C
        for r in range(R):
            for c in range(C):
                newval=0
                smn=self.getSumNeigh(r,c)
                if A[r][c]==1:
                    if smn==2 or smn==3: newval=1
                elif smn==3: newval=1
                B[r][c]=newval
        for r in range(R):
            for c in range(C):
                board[r][c]=B[r][c]
