from collections import Counter
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        w=len(words)
        N=len(s)
        if w==0 or N==0: return []
        k=len(words[0])
        HM=dict(zip(words,list(range(0,w))))
        
        T=['x']*N
        for i in range(0,N-k+1):
            wo=s[i:i+k]
            if wo in HM:
                T[i]=HM[wo]
        
        ND=Counter(words)
        ret=[]
        
        for j in range(0,k):
            SN=dict(zip(words,[0]*w))
            for i in range(j,(w-1)*k+j,k):
                idx = T[i]
                if idx != 'x':
                    SN[words[idx]]+=1          
            #print('sn {}'.format(SN))
            for i in range((w-1)*k+j,N,k):
                #add
                idx = T[i]
                if idx != 'x':
                    SN[words[idx]]+=1
                    
                #check
                if SN==ND:
                    ret.append(i-(w-1)*k)                        
                    
                #rm
                bi = T[i-(w-1)*k]
                if bi != 'x':
                    SN[words[bi]]-=1
                #print('i-wk {} bi {} sn {}'.format(i-(w-1)*k, bi, SN))

                    
        return ret
        
