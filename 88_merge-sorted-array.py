class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify   in-place instead.
        """
        P=m+n-1
        F1=m-1
        F2=n-1
        while P >= 0:
            #f1=f2=-float('inf')
            if F1>=0:
                f1=nums1[F1]
            if F2>=0:
                f2=nums2[F2]
            if F1>=0 and F2>=0:
                if f1>f2:
                    nums1[P]=f1
                    F1-=1
                else:
                    nums1[P]=f2
                    F2-=1                
            elif F1>=0:
                nums1[P]=f1
                F1-=1
            elif F2>=0:
                nums1[P]=f2
                F2-=1
            P-=1                    
                
        
