class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& G) {
        int n = G.size();
        if(n==0){return 0;}
        int m = G[0].size();
        if(m==0){return 0;}
        
        vector<vector<unsigned long long int>> A(n, vector<unsigned long long int>(m));
        //corner
        A[n-1][m-1] = G[n-1][m-1]==0 ? 1 : 0;
        
        //bottom line
        for (int c=m-2;c>=0;c--){
                A[n-1][c] = G[n-1][c]==0 ? A[n-1][c+1] : 0;
        }
        
        //right column
        for (int r=n-2;r>=0;r--){
            A[r][m-1] = G[r][m-1]==0 ? A[r+1][m-1] : 0;
        }
        
        for(int r=n-2;r>=0;--r){
            for(int c=m-2;c>=0;--c){
                A[r][c] = G[r][c] == 0 ? A[r+1][c] + A[r][c+1] : 0;
            }
        }
        
        return A[0][0];

    }
};
