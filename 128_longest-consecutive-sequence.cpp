class Solution {
public:
    int longestConsecutive(vector<int>& n) {
        
        if(n.size()==0){return 0;}
        if(n.size()==1){return 1;}
        
        unordered_map<int,bool> HM;
        
        for(auto& x: n){
            HM[x]=false;
        }
        
        int mxlen=1;
        
        for(auto& kv: HM){
            if(kv.second){continue;}
            
            //go up
            int u=kv.first+1;
            while(1){
                if(HM.find(u) != HM.end()){
                    HM[u]=true;
                    ++u;
                    continue;
                }
                break;
            }
            
            //go down
            int l=kv.first-1;
            while(1){
                if(HM.find(l)!= HM.end()){
                    HM[l]=true;
                    --l;
                    continue;
                }
                break;
            }
            
            int tmp = u-l+1-2;
            mxlen=max(mxlen,tmp);
        }
        
        return mxlen;
    }
};
