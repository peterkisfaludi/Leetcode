class Solution:
    def dfs(self, coord):
        if coord in self.V: return
        x=coord[0]; y=coord[1]
        if x<0 or x>=self.R or y<0 or y>=self.C: return
        if self.board[x][y]=='X': return
        self.V.add(coord)
        self.dfs((x-1,y))
        self.dfs((x+1,y))
        self.dfs((x,y-1))
        self.dfs((x,y+1))
        
    def solve(self, board) -> None:
        self.R=len(board)
        if self.R==0: return
        self.C=len(board[0])
        if self.C==0: return
        self.board=board
        borders=set()
        for r in range(self.R):
            for c in range(self.C):
                if board[r][c]=='O':
                    if r==0 or r==self.R-1 or c==0 or c==self.C-1:
                        borders.add((r,c))
        self.V=set()
        for x in borders:
            self.dfs(x)
        for r in range(self.R):
            for c in range(self.C):
                if (r,c) not in self.V:
                    board[r][c]='X'
        
