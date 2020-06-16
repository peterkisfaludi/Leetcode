class Solution {
public:
    int canCompleteCircuit(vector<int>& G, vector<int>& C) {
        int N=G.size();
        vector<int> D(N);
        for(int i=0;i<N;++i){
            D[i]=G[i]-C[i];
        }
        
        int d=D[0];
        int gp=0;
        int rp=0;
        
        while(1){
            if(d>=0){
                ++rp;
                if(rp==N){rp=0;}
                if(rp==gp){
                    if(d>=0){return gp;}
                    else{return -1;}
                }
                d+=D[rp];
            } else {
                --gp;
                if(gp==-1){gp=N-1;}
                if(rp==gp){
                    if(d>=0){return gp;}
                    else{return -1;}
                }
                d+=D[gp];
            }
        }
    }
};
