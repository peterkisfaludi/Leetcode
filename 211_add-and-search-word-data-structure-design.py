class Node:
    def __init__(self):
        self.d={}
        self.t=False

class WordDictionary:

    def __init__(self):
        self.root=Node()
        

    def addWord(self, word: str) -> None:
        node=self.root
        for c in word:
            if c not in node.d:
                node.d[c]=Node()
            node=node.d[c]
        node.t=True

    def search(self, word: str) -> bool:
        nodes=[self.root]
        for c in word:
            if nodes==[]: return False
            nn=[]
            if c=='.':
                for n in nodes:
                    nn.extend(list(n.d.values()))    
            else:
                for n in nodes:
                    if c in n.d:
                        nn.append(n.d[c])
            nodes=nn
        ret = False
        for n in nodes:
            ret = ret or n.t
        return ret

        


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
