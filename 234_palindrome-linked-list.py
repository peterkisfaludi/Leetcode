class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        arr=[]
        n=head
        while n is not None:
            arr.append(n.val)
            n=n.next
        #print(arr)

        N=len(arr)
        if N<=1: return True
        for i in range(0,N//2):
            if arr[i]!=arr[N-i-1]: return False
        return True
