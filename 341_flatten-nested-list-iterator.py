# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def isInteger(self) -> bool:
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        """
#
#    def getInteger(self) -> int:
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        """
#
#    def getList(self) -> [NestedInteger]:
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        """

class NestedIterator:
    def visit(self, ni):
        if ni.isInteger():
            self.A.append(ni.getInteger())
            return
        for x in ni.getList():
            self.visit(x)
            
    def __init__(self, nestedList: [NestedInteger]):
        self.A=[]
        nl=nestedList
        for x in nl:            
            self.visit(x)        
        self.idx=-1
        self.N=len(self.A)

    def next(self) -> int:
        self.idx+=1
        if self.idx<self.N:
            return self.A[self.idx]
        return None
    def hasNext(self) -> bool:
         return self.idx<self.N-1

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())
