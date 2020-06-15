class Solution:
    def visit(self, w, path):
        path.append(w)
        #print(path)
        if len(path)>self.min_len:
            path.pop(); return
        if w==self.endWord:
            self.ret.append(path.copy())
            #print('#')
        else:
            for n in self.HM[w]:
                self.visit(n,path)
        path.pop()
        
    def getNeigh(self, w):
        #import pdb;pdb.set_trace()
        ret=set()
        for ne in self.wordList:
            if ne == w: continue
            if self.NE[w].intersection(self.NE[ne]):
                ret.add(ne)
        return ret
    def possibleNeighs(self, w):
        ret=set()
        for i in range(len(w)):
            tmp=w[0:i]+'#'+w[i+1:]
            ret.add(tmp)
        return ret
            
    def findLadders(self, beginWord: str, endWord: str, wordList):
        self.NE={}
        self.HM={}
        self.HM[beginWord]=set()
        for x in wordList:
            self.HM[x]=set()
        if endWord not in self.HM: return []
        self.endWord=endWord
        self.wordList=wordList
        self.NE[beginWord]=self.possibleNeighs(beginWord)
        for w in wordList:
            self.NE[w]=self.possibleNeighs(w)
        #wavefronts
        PQ=[set(),set()]
        Q=[set(),set()]; Q[0].add(beginWord); Q[1].add(endWord)
        min_len=None
        iter=0
        while min_len is None:
            if len(Q[0])==0 or len(Q[1])==0: break
            idx=0
            if len(Q[0])>len(Q[1]): idx=1
            NQ=set()
            iter+=1
            for w in Q[idx]:
                if w in Q[idx^1]: min_len=iter
                for ne in self.getNeigh(w):
                    if ne in PQ[idx] or ne in Q[idx]:continue
                    NQ.add(ne)
                    if idx==0: self.HM[w].add(ne)
                    else: self.HM[ne].add(w)
            
            PQ[idx]=Q[idx]
            Q[idx]=NQ
            
        #import pdb;pdb.set_trace()
        #dfs
        self.ret=[]
        if min_len is None: return []
        self.min_len=min_len
        #print(min_len)
        #print(self.HM)
        self.visit(beginWord,[])
        return self.ret
