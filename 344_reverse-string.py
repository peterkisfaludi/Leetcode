class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        N=len(s)
        for i in range(0,N//2):
            tmp = s[i]
            s[i] = s[N-i-1]
            s[N-i-1] = tmp
        
            
        
