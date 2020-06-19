class Solution {
public:
    typedef enum {
        U,
        D,
        L,
        R
    } State;

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        int N=n*n;
        
        int r=0;
        int c=0;
        int rmin=0;
        int cmin=-1;
        int rmax=n;
        int cmax=n;
        
        State s = R;
        for(int i=0;i<N;++i){
            ret[r][c]=i+1;
            switch(s){
                case R:
                {
                ++c;
                if(c==cmax){
                    s=D;
                    ++r;
                    --cmax;
                    --c;
                }
                break;
                }
                
                case D:
                {
                ++r;
                if(r==rmax){
                    s=L;
                    --c;
                    --rmax;
                    --r;
                }
                break;
                }
                
                case L:
                {
                --c;
                if(c==cmin){
                    s=U;
                    --r;
                    ++cmin;
                    ++c;
                }
                break;
                }
                
                case U:
                {
                --r;
                if(r==rmin){
                    s=R;
                    ++c;
                    ++rmin;
                    ++r;
                }
                break;
                }
            }
        }
        
        return ret;
    }
};
