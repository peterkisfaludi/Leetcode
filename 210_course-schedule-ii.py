class Solution:
    def Do(self, i, dep, stat, ret):
        #print(stat)
        if stat[i]==1: #doing
            print('doing')
            return False
        if stat[i]==2: #done
            return True
        if stat[i]==0: #todo
            stat[i]=1
            for d in dep[i]:
                if self.Do(d, dep, stat, ret) != True:
                    return False
            stat[i]=2
            ret.append(i)
            return True

    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        N=numCourses
        inp=prerequisites
        # build deps
        dep=[None]*N
        for i in range(0,N):
            dep[i]=[]
        for d in inp:
            dep[d[0]].append(d[1])

        #parse deps
        stat = [0]*N
        ret = []
        for i in range(0,N):
            self.Do(i, dep, stat, ret)
        #print(stat)
        if stat == [2]*N:
            return ret
        return []
        
