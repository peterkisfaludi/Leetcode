class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        
        m=len(matrix)
        if m==0: return []
        n=len(matrix[0])
        if n==0: return []
        ret=[None]*(m*n)
        
        r=0
        c=-1
        
        top=0
        bottom=m
        left=0
        right=n
        
        dir='R'
        i=0
        while i < m*n:            
            if dir=='R':
                c+=1
                if c==right:
                    top+=1
                    c-=1
                    dir='D'
                    continue
            elif dir=='D':
                r+=1
                if r==bottom:
                    right-=1
                    r-=1
                    dir='L'
                    continue
            elif dir=='L':
                c-=1
                if c<left:
                    bottom-=1
                    c+=1
                    dir='U'
                    continue
            elif dir=='U':
                r-=1
                if r<top:
                    left+=1
                    r+=1
                    dir='R'
                    continue
            ret[i]=matrix[r][c]
            i+=1
        return ret
                    
                
        
