class Solution:
    def deleteNode(self, node):
        arr=[]
        head=node
        n=head
        while n is not None:
            arr.append(n.val)
            n=n.next
        #print(arr)

        n=head
        prv=None
        for x in arr[1:]:
            n.val=x
            prv=n
            n=n.next
        prv.next=None
