import math
class Solution:
    def maxProduct(self, nums) -> int:
        N=len(nums)
        if N==0: return 0
        if N==1: return nums[0]
        
        ninf=float('-inf')
        mp=ninf
        A,B,C,D,E=ninf,ninf,ninf,ninf,ninf
        FN,LN=None,None
        for i in range(0,N):
            n=nums[i]
            if n==0:
                mp=max(mp,0)
                mp=max(mp,A,B,C,D,E)
                #print(A,B,C,D,E)
                A,B,C,D,E=ninf,ninf,ninf,ninf,ninf
                FN,LN=None,None
                continue
            if not FN is None:
                if math.isinf(E): E=n
                else: E*=n
            if n<0:
                if FN is None: FN=n;A=C
                LN=n;B=ninf;D=C
            else:
                if math.isinf(B): B=n
                else: B*=n
            if math.isinf(C): C=n
            else: C*=n
        
        #print(A,B,C,D,E)
        return max(mp,A,B,C,D,E)
