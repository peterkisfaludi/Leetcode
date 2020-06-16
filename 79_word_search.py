class Solution:
    def visit(self, idx, row, col, visited):
        if idx==len(self.word): return True
        if row<0 or col < 0 or row>=self.R or col>=self.C: return False
        if (row,col) in visited: return False
        if self.word[idx]!=self.board[row][col]: return False
        visited.add((row,col))
        idx+=1
        return  self.visit(idx, row+1, col, visited.copy()) or \
                self.visit(idx, row-1, col, visited.copy()) or \
                self.visit(idx, row, col+1, visited.copy()) or \
                self.visit(idx, row, col-1, visited.copy())
    def exist(self, board: List[List[str]], word: str) -> bool:
        self.word=word
        self.board=board
        if len(word)==0: return True
        self.R=len(board)
        if self.R==0: return False
        self.C=len(board[0])
        if self.C==0: return False
        found=False
        for r in range(self.R):
            for c in range(self.C):
                found = found or self.visit(0,r,c, set())
                if found: break
        return found
        
        
