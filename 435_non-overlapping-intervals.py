class Solution:
    def eraseOverlapIntervals(self, intervals) -> int:
        cnt=0
        sivals = sorted(intervals, key = lambda x : x[1])
        if len(sivals)<=1:return 0
        end=sivals[0][1]
        for ival in sivals[1:]:
            if ival[0]>=end:end=ival[1]
            else: cnt+=1
        return cnt
        
