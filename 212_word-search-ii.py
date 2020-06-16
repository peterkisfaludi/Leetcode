class Node:
    def __init__(self):
        self.terminal=False
        self.D={}
        self.w=''

class Trie:
    def __init__(self):
        self.root=Node()
    def add(self, word):
        n=self.root
        for c in word:
            if c not in n.D: n.D[c]=Node()
            n=n.D[c]
        n.terminal=True
        n.w=word
                
class Solution:
    def visit(self, row, col, vis, node):
        if node.terminal:
            self.op.add(node.w)
        if row<0 or col < 0 or row>=self.R or col>=self.C: return
        if (row,col) in vis: return
        if self.board[row][col] not in node.D: return
        vis.add((row,col))
        node = node.D[self.board[row][col]]
        self.visit(row+1, col, vis.copy(), node)
        self.visit(row-1, col, vis.copy(), node)
        self.visit(row, col+1, vis.copy(), node)
        self.visit(row, col-1, vis.copy(), node)
        
    def findWords(self, board, words):        
        self.board=board
        op=[]
        W=len(words)
        if W==0: return op
        self.R=len(board)
        if self.R==0: return op
        self.C=len(board[0])
        if self.C==0: return op

        trie = Trie()
        for wi in range(W):            
            trie.add(words[wi])
        
        self.op=set()
        for r in range(self.R):
            for c in range(self.C):
                node=trie.root
                self.visit(r,c,set(),node)
        return list(self.op)
