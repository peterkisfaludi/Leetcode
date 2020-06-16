class Solution:
    def search(self, nums: List[int], target: int) -> int:
        N=len(nums)
        if N==0: return -1
        if N==1:
            if nums[0]==target:
                return 0
            else:
                return -1
        t=target
        B=0
        E=N-1
        
        while True:
            M=(B+E)//2        
            b=nums[B]
            e=nums[E]
            m=nums[M]
            
            if t==b: return B
            if t==e: return E
            if t==m: return M
            if B==E or B==M or E==M: return -1
            if b<e:
                #normal
                if t < b: return -1
                if t > e: return -1
                if t < m: E=M
                if t > m: B=M
            else:
                if t < b and t > e: return -1
                if t > b and t < m: E=M
                if t < e and t > m: B=M
                if t > b and t > m:
                    if m>b: B=M
                    else: E=M
                if t < e and t < m:
                    if m<e: E=M
                    else: B=M
                            
                
                
            
