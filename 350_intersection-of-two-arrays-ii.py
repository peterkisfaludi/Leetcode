from typing import List
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        n1=sorted(nums1)
        n2 = sorted(nums2)
        N1=len(n1)
        N2=len(n2)
        p1=0
        p2=0
        ret=[]
        while p1<N1 and p2<N2:
            x1=n1[p1]
            x2=n2[p2]
            if x1==x2:
                ret.append(x1)
                p1+=1
                p2+=1
            if x1<x2:
                p1+=1
            if x2<x1:
                p2+=1
        return ret
