import random
class RandomizedSet:
            
    def hashfun(self,val: int):
        return 7*pow(val,5) % self.cap
        
    def rehash(self):
        self.cap*=2
        dbl_arr=[]
        self.nm=[0]*self.cap
        for i in range(0,self.cap):
            dbl_arr.append([])
        
        for lst in self.arr:
            for e in lst:
                hv = self.hashfun(e)
                dbl_arr[hv].append(e)
                self.nm[hv]+=1
        
        self.arr=dbl_arr
        
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.arr=[]
        self.arr.append([])
        self.nm=[0]
        self.cap=1
        self.load=0

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        """
        hv=self.hashfun(val)
        lst = self.arr[hv]
        if val in lst: return False
        lst.append(val)
        self.nm[hv]+=1
        self.load+=1
        if self.load / self.cap > 0.7:
            self.rehash()
        return True

    def remove(self, val: int) -> bool:
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        """
        hv=self.hashfun(val)
        lst = self.arr[hv]
        if val in lst:
            del lst[lst.index(val)]
            self.nm[hv]-=1
            return True
        return False
        

    def getRandom(self) -> int:
        """
        Get a random element from the set.
        """
        lst = random.choices(population=self.arr, weights=self.nm, k=1)
        return random.choice(lst[0])

# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
