class Solution {
public:
    static const unsigned int L = 0x01;
    static const unsigned int D = 0x02;
    static const unsigned int R = 0x04;

    vector<vector<string>> solveNQueens(int N) {
        vector<vector<int>> T(N, vector<int>(N,0));
        vector<int> A(N, -1);
        vector<vector<string>> ret;
        
        string dots="";
        for(int i=0;i<N;++i){
            dots+='.';
        }
        
        vector<int> zeros(N,0);
        
        int r=0;
        while(true){
            //1. place
            while(true){
                ++A[r];
                if(A[r]==N){
                    if(r==0){
                        //no more solution
                        return ret;
                    } else {
                        A[r] = -1;
                        T[r] = zeros;
                        --r;
                        continue;
                    }
                } else { 
                    if(T[r][A[r]] == 0){
                        //not hit    
                        break; //go to propagate
                    } else {
                        //was hit
                        continue;
                    }
                }
            }
            #if 0
            for(auto x:A){
                cout << x << endl;
            }
            cout << "-----" << endl;
            #endif
            
            //found a solution?
            if(r==N-1) {
                vector<string> tmp;
                for(int i=0;i<N;++i){
                    string d = dots;
                    d[A[i]]='Q';
                    tmp.push_back(d);
                }
                ret.push_back(tmp);
                continue;
            }
            
            //2. propagate
            
            //propagate other Qs
            for(int i=0;i<N;++i){
                if((T[r][i] & L) || (i==A[r])){
                    if(i-1>=0){
                        T[r+1][i-1] |=L;
                    }
                }
                if((T[r][i] & R) || (i==A[r])){
                    if(i+1<=N-1){
                        T[r+1][i+1] |=R;
                    }
                }
                if((T[r][i] & D) || (i==A[r])){
                    T[r+1][i] |=D;
                }
            }
            #if 0
            for(auto row:T){
                for(auto col:row){
                    cout << col << "  ";
                }
                cout << endl;
            }
            cout << "###"<<endl;
            #endif
            ++r;
        }
    }
};
