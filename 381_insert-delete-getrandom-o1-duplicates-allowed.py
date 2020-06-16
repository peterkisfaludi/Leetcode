class RandomizedCollection:

    def __init__(self):
        self.T=[]
        self.HM={}

    def insert(self, val: int) -> bool:
        ret=False
        self.T.append(val)
        if val not in self.HM:
            ret=True       
            self.HM[val]=set()
        self.HM[val].add(len(self.T)-1)   
        #print(self.T, self.HM)
        return ret

    def remove(self, val: int) -> bool:
        ret=False
        if val in self.HM:
            ret=True
            idx=next(iter(self.HM[val]))
            self.HM[val].discard(idx)
            if idx!=len(self.T)-1:
                self.T[idx]=self.T[-1]
                self.HM[self.T[idx]].add(idx)
            self.HM[self.T[idx]].discard(len(self.T)-1)
            if len(self.HM[val])==0: del self.HM[val]
            self.T.pop()
        #print(self.T, self.HM)
        return ret

    def getRandom(self) -> int:
        return self.T[random.randrange(0,len(self.T))]
