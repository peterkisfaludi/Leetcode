class Node:
    def __init__(self):
        self.D={}
        self.terminal=False
class Trie:
    def __init__(self):
        self.root=Node()
    def add(self, w):
        n=self.root
        for ch in w:
            if ch not in n.D:
                n.D[ch]=Node()
            n=n.D[ch]
        n.terminal=True
class Solution:
    def wordBreak(self, s: str, wordDict) -> bool:
        N=len(s)
        trie=Trie()
        for w in wordDict:
            trie.add(w)
        Q=set()
        S=set()
        Q.add(0)
        S.add(0)
        while Q:
            #print(Q)
            i=Q.pop()
            if i==N: return True
            n=trie.root
            while True:
                if i==N: break
                ch=s[i]
                if ch in n.D:
                    n=n.D[ch]
                    if n.terminal:
                        if i+1 not in S:
                            Q.add(i+1)
                            S.add(i+1)
                    i+=1
                else:
                    break
        return False
