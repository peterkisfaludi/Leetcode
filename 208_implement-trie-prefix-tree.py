class Trie:
    
    class Node:
        def __init__(self):
            self.hm={}
            self.terminal=False

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = self.Node()

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        node = self.root
        for c in word:
            if c not in node.hm:
                node.hm[c]=self.Node()
            node=node.hm[c]
        node.terminal=True
        

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        node = self.root
        for c in word:
            if c not in node.hm:
                return False
            node=node.hm[c]
        return node.terminal
        

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        node = self.root
        for c in prefix:
            if c not in node.hm:
                return False
            node=node.hm[c]
        return True
