class Solution:

    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        R = len(matrix)
        if R==0: return 0
        C = len(matrix[0])
        if C==0: return 0
            
        #init T
        T=[None]*R
        for r in range(R):
            T[r]=[0]*C
        
        Q=[]
        Q2=[]
        path=1
        #find local minima
        for r in range(0,R):
            for c in range(0,C):
                e=matrix[r][c]
                isMin=True
                if r-1>=0 and matrix[r-1][c]<e: isMin=False; continue
                if r+1<R and matrix[r+1][c]<e: isMin=False; continue
                if c-1>=0 and matrix[r][c-1]<e: isMin=False; continue
                if c+1<C and matrix[r][c+1]<e: isMin=False; continue
                if isMin:
                    Q.append((r,c))
                    T[r][c]=path
        #process
        while True:
            path+=1
            while len(Q)>0:
                r,c=Q.pop()
                e=matrix[r][c]
                if r-1>=0 and matrix[r-1][c]>e:
                    if path>T[r-1][c]:
                        T[r-1][c]=path
                        Q2.append((r-1,c))
                if r+1<R and matrix[r+1][c]>e:
                    if path>T[r+1][c]:
                        T[r+1][c]=path
                        Q2.append((r+1,c))
                if c-1>=0 and matrix[r][c-1]>e:
                    if path>T[r][c-1]:
                        T[r][c-1]=path
                        Q2.append((r,c-1))
                if c+1<C and matrix[r][c+1]>e:
                    if path>T[r][c+1]:
                        T[r][c+1]=path
                        Q2.append((r,c+1))
            
            if len(Q2)>0:
                Q=Q2
                Q2=[]
            else:          
                return path-1
                    
         
