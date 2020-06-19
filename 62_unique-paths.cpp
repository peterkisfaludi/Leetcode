class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m==1 && n==1){ return 1;}
        
        vector<vector<int>> A(n, vector<int>(m));
        A[n-1][m-1] = 1;
        for (int c=m-1;c>=0;c--){
            A[n-1][c] = 1;
        }
        for (int r=n-1;r>=0;r--){
            A[r][m-1] = 1;
        }
        
        for(int r=n-2;r>=0;--r){
            for(int c=m-2;c>=0;--c){
                A[r][c] = A[r+1][c] + A[r][c+1];
            }
        }
        
        return A[0][0];

    }
};
