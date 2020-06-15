class Solution:
    def candy(self, ratings: List[int]) -> int:
        N=len(ratings)
        nums=[0]*N
        
        if N==0:return 0
        if N==1: return 1
        
        i=0
        while True:
            #find local min
            loc_min=False
            if i==0:
                loc_min = ratings[0]<=ratings[1]
            loc_min = ratings[i]<=ratings[i+1] and ratings[i]>=ratings[i-1]
            
            if loc_min:
                nums[i]=1
                #go left
                j=i-1
                
                go_left = True
                while go_left:
                    if j<0:
                        break
                    if ratings[j]>=ratings[j+1]:
                        go_left = False
                    if j-1>=0:
                        if ratings[j]>=ratings[j-1]:
                            go_left = False
                    nums[j]=1+nums[j+1]
                    j-=1
                #go right
                while True:
                    if j<N:
                        if ratings[j]>=ratings[j+1] and ratings[j]>=ratings[j-1]:
                            break
                    else:
                        break
                    nums[j]=1+nums[j-1]
                    j+=1
                i=j
            i+=1
            if i==N:
                break
                        
        return sum(nums)
