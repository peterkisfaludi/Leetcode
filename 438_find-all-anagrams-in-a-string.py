class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        
        from collections import OrderedDict
        P=len(p)
        S=len(s)

        ret =[]
        if P>S: return ret
        if P==0: return ret

        pa = OrderedDict()
        for c in p:
            if c in pa:
                pa[c]+=1
            else:
                pa[c]=1
        sa = pa.copy()
        for k,v in sa.items():
            sa[k]=0

        for i in range(0,P-1):
            c=s[i]
            if c in sa:
                sa[c]+=1
            
        for i in range(P-1,S):
            c=s[i]
            if c in sa:
                sa[c]+=1        
                if sa==pa:
                    ret.append(i-P+1)
            
            c2 = s[i-P+1]
            if c2 in sa:
                sa[c2]-=1
        
        return ret
