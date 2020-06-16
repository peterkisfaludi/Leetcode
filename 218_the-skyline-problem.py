from sortedcontainers import SortedSet, SortedDict
class Solution:
    def getSkyline(self, buildings):
        C = SortedDict()
        for b in buildings:
          if b[0] not in C:
            C[b[0]]=[[],[]]
          if b[1] not in C:
            C[b[1]]=[[],[]]
          C[b[0]][0].append(b[2])
          C[b[1]][1].append(b[2])
        op = []
        heap = SortedDict()
        for x,h_lst in C.items():
          for r in h_lst[1]:
            heap[r]-=1
            if heap[r]==0: del heap[r]
          for l in h_lst[0]:
            if l not in heap: heap[l]=0
            heap[l]+=1
          val=0
          if heap: val=heap.peekitem()[0]
          if op and op[-1][1]==val:continue
          op.append([x,val])
        return op
