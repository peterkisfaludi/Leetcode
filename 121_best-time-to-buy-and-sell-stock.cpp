class Solution {
public:
    int maxProfit(vector<int>& P) {

    int N=P.size();
    if(N<=1){return 0;}
    
    int mn = P[0];
    int mx = P[0];
    int mp = 0;
    for(int i=1;i<N;++i){
        int a=P[i];
        if(a<mn){mn=a;mx=a;}
        else if(a>mx){mx=a; mp=max(mp,mx-mn);}
    }
    
    return mp>0?mp:0;
    }
};
