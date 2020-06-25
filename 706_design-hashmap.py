from collections import deque
class Entry:
    def __init__(self, k, v):
        self.key = k
        self.val = v

class MyHashMap:
    def hashfun(self, key):
        return 5*pow(key,3) % 10000        
    
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.arr = deque()
        for i in range(0,10000):
            self.arr.append([])
        
    def put(self, key: int, value: int) -> None:
        """
        value will always be non-negative.
        """
        idx = self.hashfun(key)
        e_list = self.arr[idx]
        for i in range(0, len(e_list)):
            if e_list[i].key == key:
                e_list[i].val = value
                return
        e_list.append(Entry(key,value))                        

    def get(self, key: int) -> int:
        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        """
        idx = self.hashfun(key)
        e_list=self.arr[idx]
        for e in e_list:
            if e.key==key:
                return e.val
        return -1

    def remove(self, key: int) -> None:
        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        """
        idx = self.hashfun(key)
        e_list = self.arr[idx]        
        for i in range(0,len(e_list)):
            if e_list[i].key==key:
                del e_list[i]
                return
        


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)
