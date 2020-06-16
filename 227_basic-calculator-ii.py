class Solution:
    def getResult(self, a, b , op):
        if op=='+': return a+b
        if op=='-': return a-b
        if op=='/': return a//b
        if op=='*': return a*b
    def getOp(self, i):
        if i>=self.N: return None, i+1
        return self.s[i], i+1
    def getNum(self,i):
        numstr=""
        while True:
            if i>=self.N: break
            ch=self.s[i]
            if ch in ['+', '-', '*', '/']: break
            numstr+=ch
            i+=1
        return int(numstr), i
    def getRight(self, i):
        tmp,i=self.getNum(i)
        while True:
            op,i=self.getOp(i)
            if op is None or op in ['+', '-']: return tmp, i-1
            num,i=self.getNum(i)
            tmp=self.getResult(tmp,num,op)
    def calculate(self, s: str) -> int:
        s2=""
        for x in s:
            if x == ' ': continue
            s2+=x
            
        self.s=s2
        self.N=len(self.s)
        i=0
        left,i = self.getNum(i)
        while True:
            op, i = self.getOp(i)
            if op is None: return left
            if op in ['+', '-']:
                right,i=self.getRight(i)
            else:
                right, i= self.getNum(i)
            left=self.getResult(left,right,op)
