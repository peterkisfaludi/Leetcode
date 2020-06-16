from collections import Counter,deque
class Rec:
    def __init__(self, cnt_, idx_):
        self.cnt=cnt_
        self.idx=deque(maxlen=cnt_)
        self.idx.append(idx_)
    def __str__(self):
        return 'cnt {} idx {}'.format(self.cnt, self.idx)
    def __repr__(self):
        return self.__str__()

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        fac=len(t)
        N=len(s)
        D=Counter(t)
        min_len=N+1
        LI=-1
        for k,v in D.items():
          D[k]=Rec(v,-1)
        for i in range(0,N):
          c=s[i]
          if c not in D:
            continue
          D[c].idx.append(i)      
          if D[c].cnt > 0:
            D[c].cnt-=1
            fac-=1
          if fac==0:
            FI = min([x.idx[0] for x in D.values()])
            act_len=i-FI+1
            if act_len < min_len:
              min_len=act_len
              LI=i
            #print('i {} D {} actlen {}'.format(i,D,act_len))
        #print('LI {} minlen {}'.format(LI,min_len))
        if LI != -1:
            return s[LI-min_len+1:LI+1]
        else:
            return ""

        
