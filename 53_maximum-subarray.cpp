class Solution {
public:
    int maxSubArray(vector<int>& A) {
        int N=A.size();
        
        if(N==0){return 0;}
        if(N==1){return A[0];}
        
        auto S=vector<int>(N);
        S[0]=A[0];
        int mx=S[0];
        
        for(int i=1;i<N;i++){
            int cntsum = S[i-1] + A[i];
            if(A[i]>cntsum){
                S[i]=A[i];
            } else {
                S[i]=cntsum;
            }
            mx=max(mx,S[i]);
        }
        
        return mx;
    }
};
