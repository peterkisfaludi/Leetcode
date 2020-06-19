class Solution {
public:
    int minPathSum(vector<vector<int>>& A) {
        int M=A.size();
        if(M==0){
            return 0;
        }
        int N=A[0].size();
        if(N==0){
            return 0;
        }
        if(M==1){
            int sm=0;
            for(int i=0;i<N;i++){
                sm+=A[0][i];
            }
            return sm;
        }

        if(N==1){
            int sm=0;
            for(int i=0;i<M;i++){
                sm+=A[i][0];
            }
            return sm;
        }
        
        vector<vector<int>> T = vector<vector<int>>(M,vector<int>(N));
        
        T[M-1][N-1] = A[M-1][N-1];
        //last column
        for(int i=M-2;i>=0;i--){
            T[i][N-1]=A[i][N-1] + T[i+1][N-1];
        }
        
        //last row
        for(int i=N-2;i>=0;i--){
            T[M-1][i]=A[M-1][i] + T[M-1][i+1];
        }
        
        for(int c=N-2;c>=0;c--){
            for(int r=M-2;r>=0;r--){
                T[r][c]=A[r][c] + min(T[r+1][c],T[r][c+1]);
            }
        }
        
        return T[0][0];

    }
};
