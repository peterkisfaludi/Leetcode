from collections import Counter
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        cl = list(Counter(nums).items())
        ret=[[]]
        return foo(0,cl,ret)
    
def foo(idx, cnt, ret):
        if idx==len(cnt): return ret
        new_ret=ret.copy()
        num=cnt[idx][0]
        rng=cnt[idx][1]
        #print('idx {} ret {} num {} rng {}'.format(idx,ret,num,rng))

        if idx==0:
                for i in range(1,rng+1):
                        new_ret.append([num]*i)
        else:
                for i in range(1,rng+1):
                        to_app=[num]*i
                        for r in ret:
                                row=r.copy()
                                row.extend(to_app)
                                new_ret.append(row)
        return foo(idx+1,cnt,new_ret)
