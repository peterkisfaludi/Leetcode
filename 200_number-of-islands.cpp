class Solution {
public:
    vector<vector<char>> *G;
    int N;
    int M;
    void fill(int r, int c){
        vector<vector<char>> &g = *G;
        if(g[r][c]=='1'){
            g[r][c]='2';
            
            if(r!=0)    { fill(r-1, c);}
            if(r!=N-1)  { fill(r+1, c);}
            if(c!=0)    { fill(r, c-1);}
            if(c!=M-1)  { fill(r, c+1);}
        }
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        G=&grid;
        N=grid.size();
        if(N==0){return 0;}
        M=grid[0].size();
        if(M==0){return 0;}
        
        int n=0;
        for(int r=0;r<N;++r){
            for(int c=0;c<M;++c){
                if(grid[r][c] == '1'){
                    fill(r,c);
                    ++n;
                }
            }
        }
        return n;
    }
};
