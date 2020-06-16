class Solution:
    def put(self, val, arr):
        N=len(arr)
        if N==0:
            arr.append(val)
            return True
        if N==1:
            if val<=arr[0]:
                arr[0]=val
            else:
                arr.append(val)
            return True
        if N==2:
            if val<arr[0]: return False
            if val==arr[0]: return True
            if val<=arr[1]:
                arr[1]=val
            else:
                arr.append(val)
            return True
            
    def increasingTriplet(self, nums) -> bool:
        A=[]
        B=[]
        for x in nums:
            if not self.put(x,A):
                self.put(x,B)
            #print(A,B)
            if len(A)==3: return True
            if len(A)==2 and len(B)==2:
                A=B
                B=[]
        return False
