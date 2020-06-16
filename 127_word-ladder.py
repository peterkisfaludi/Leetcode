class Solution:
    def getNeigh(self, w) -> set:
        ret=set()
        for i in range(len(w)):
            variant=w[0:i]+'#'+w[i+1:]
            if variant in self.neighList:
                for v in self.neighList[variant]:
                    if v not in self.used:
                        ret.add(v)    
                    
        return ret
    
    def ladderLength(self, beginWord: str, endWord: str, wordList) -> int:
        if endWord not in wordList: return 0
        self.wordList = wordList        
        neighList = {}
        for w in wordList:
            for i in range(len(w)):
                variant = w[0:i]+'#'+w[i+1:]
                if variant not in neighList: neighList[variant]=set()
                neighList[variant].add(w)
        self.used=set()
        self.neighList=neighList
        ws=self.getNeigh(beginWord)
        ret=2
        while ws:
            self.used.update(ws)
            #print(ws, self.used)
            nws=set()
            for w in ws:
                if endWord == w: return ret            
                nws.update(self.getNeigh(w))            
            ws=nws
            ret+=1
        return 0
