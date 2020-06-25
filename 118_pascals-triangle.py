class Solution:
    def generate(self, numRows: int):
        if numRows<1: return []
        ret=[[1]]
        for i in range(1,numRows):
            prev=ret[i-1]
            ret.append([1]*(i+1))
            act=ret[-1]
            for j in range(1,i):
                act[j]=prev[j-1] + prev[j]
        return ret
