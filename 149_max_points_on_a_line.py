from typing import List
from fractions import Fraction
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        N=len(points)
        if N==0: return 0
        if N==1: return 1
        if N==2: return 2

        gmx=0
        for i in range(0,N-1):
            HMx = {}
            HMm = {}
            overlap=0
            mx=0
            p0=points[i]
            for j in range(i+1,N):
                p1=points[j]
                dx=p0[0]-p1[0]
                dy=p0[1]-p1[1]
                if dx==0:
                    if dy==0:
                        overlap+=1
                        continue
                    else:
                        x=p0[0]
                        if x not in HMx:
                            HMx[x] = 0
                        HMx[x]+=1
                    mx=max(mx,HMx[x])
                else:
                    m=Fraction(dy,dx)
                    if m not in HMm:
                        HMm[m]=0
                    HMm[m]+=1
                    mx=max(mx,HMm[m])
            gmx=max(gmx,mx+overlap+1)
      
        return gmx
