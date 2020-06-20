class Solution {
public:
    void rotate(vector<vector<int>>& M) {
        int N=M.size();
        if(N==0 || N==1){return;}
        
        for(int R=0;R<N/2;R++){
            for(int C=R;C<N-(R+1);C++){
                int t1=M[R][C];
                int t2=M[C][N-1-R];
                int t3=M[N-1-R][N-1-C];
                int t4=M[N-1-C][R];
                
                M[C][N-1-R]=t1;
                M[N-1-R][N-1-C]=t2;
                M[N-1-C][R]=t3;
                M[R][C]=t4;
            }
        }
    }
};
