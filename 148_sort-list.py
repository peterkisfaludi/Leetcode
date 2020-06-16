def list2List(head, n):
    ret=[]
    for i in range(n):
        ret.append(head.val)
        head=head.next
    return ret
class Solution:
    def getLen(self, h):
        n=0
        while h is not None:
            h=h.next
            n+=1
        return n
    def chop(self, h, n):
        b=h
        m=n//2
        for i in range(m):
            b=b.next
        return (h, m, b, n-m)
    def merge(self, A, na, B, nb):
        total=na+nb
        if A.val > B.val:
            tmp=A
            A=B
            B=tmp
            tmp=na
            na=nb
            nb=tmp
        #print('merging',list2List(A,na),list2List(B,nb))
            
        H=A
        PA=None
        while nb>0:
            #print('while',na,nb)
            if na>0 and (A.val <= B.val):
                PA=A
                A=A.next
                na-=1
            else:
                PA.next=B
                NB=B.next
                B.next=A
                PA=B
                B=NB
                nb-=1
        #print('merged',list2List(H,total))
        return H
    def sort(self, h, n):
        #print('sorting',list2List(h,n),n)
        if n==1: return h
        A, na, B, nb = self.chop(h, n)
        A=self.sort(A,na)
        B=self.sort(B,nb)
        ret = self.merge(A,na,B,nb)
        #print('sorted',list2List(ret,n))
        return ret
        
    def sortList(self, head: ListNode) -> ListNode:
        N=self.getLen(head)
        if N<=1: return head
        ret = self.sort(head,N)
        n=ret
        for i in range(N-1):
            n=n.next
        n.next=None
        return ret
