class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& D) {
        int N=D.size();
        if(N==0){return -1;}
        int M=D[0].size();
        if(M==0){return -1;}
        
        vector<vector<int>> H(N, vector<int>(M));
        
        H[N-1][M-1]=1;
        if(D[N-1][M-1]<0){
            H[N-1][M-1]-=D[N-1][M-1];
        }
        
        for(int i=N-2;i>=0;--i){
            H[i][M-1]=max(1,H[i+1][M-1]-D[i][M-1]);
        }
        
        for(int i=M-2;i>=0;--i){
            H[N-1][i]=max(1,H[N-1][i+1]-D[N-1][i]);
        }
        
        for(int R=N-2;R>=0;--R){
            for(int C=M-2;C>=0;--C){
                int nHp = min(H[R+1][C],H[R][C+1]);
                H[R][C]=max(1,nHp-D[R][C]);
            }
        }
        return H[0][0];
    }
};
