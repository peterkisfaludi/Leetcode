class Solution:
    def isPalindrome(self, s: str) -> bool:
        N=len(s)
        bi = 0
        ei = N-1
        while bi < ei:
            b=s[bi]
            e=s[ei]            
            if not b.isalnum():
                bi+=1
                continue
            if not e.isalnum():
                ei-=1
                continue
            if b.upper()!=e.upper():
                return False
            bi+=1
            ei-=1
        return True
