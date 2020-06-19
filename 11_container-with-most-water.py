class Solution:
    def maxArea(self, height: List[int]) -> int:
        mx=0
        B=0
        N=len(height)
        F=N-1
        
        while(F-B>0):
            hB=height[B]
            hF=height[F]
            mx=max(mx, min(hB,hF)*(F-B))
            if hB<hF:
                B+=1
            else:
                F-=1
        return mx
