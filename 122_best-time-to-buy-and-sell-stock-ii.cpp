class Solution {
public:
    int maxProfit(vector<int>& P) {
    int N=P.size();
    if(N<=1){return 0;}
    
    int p=0;
    int b=P[0];
    int s=P[0];
    for(int i=1;i<N;++i){
        int a=P[i];
        if(a<s || a<b){
            p+=s-b;
            b=a;
            s=a;
        } else if(a>s){
            s=a;
        }
    }
    
    if(s>b){
        p+=s-b;
    }

    return p>0?p:0;

    }
};
