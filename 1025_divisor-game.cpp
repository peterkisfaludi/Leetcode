class Solution {
public:
    bool divisorGame(int N) {
        if(N==0){
            return false;
        }
        if(N==1){
            return false;
        }
        if(N==2){
            return true;
        }
        
        typedef struct{
            int sc;
            int ovr;
        } sc_ovr_t;
        
        vector< vector<int> > T(N+1, vector<int>(N+1));
        vector<sc_ovr_t> S(N+1);
        
        //prefill S
        for(int r=1;r<=N;r++){
            S[r].sc = N;
            S[r].ovr = 0;
        }
        
        
        //prefill T
        for(int r=1;r<=N;r++){
            for(int c=1;c<=N;c++){
                if(
                    (r==0 || r==1) ||
                    (c>=r) ||
                    (r%c!=0)
                )
                {
                    T[r][c] = -1;
                    S[r].sc--;
                    if(S[r].sc==0 && S[r].ovr==0){
                        S[r].ovr=-1;
                    }
                }
            }
        }
        
        #if 0
        for(int r=1;r<=N;r++){
            for(int c=1;c<=N;c++){
                // cout << "R" << r <<" C"<<c<< " val"        <<T[r][c]<<endl;
            }
            // cout << "R" << r << " Score:" << S[r].sc << " overall:" << S[r].ovr << endl;
        }
        #endif
        
        //fill T row by row N=2,3,...
        for(int r=2;r<=N;r++){
            for(int c=1;c<=N;c++){
                //not filled in yet, candidate field
                if(T[r][c]==0){
                    //which row would it jump back (N-x), is that row winning or losing
                    //pointing to losing row -> N is winner
                    if(S[r-c].ovr==-1){
                        T[r][c] = 1;
                        
                        //winner row found
                        S[r].sc=0;
                        S[r].ovr=1;

                    } else if(S[r-c].ovr==1){
                        T[r][c] = -1;
                        S[r].sc--;
                        if(S[r].sc==0 && S[r].ovr==0){
                            S[r].ovr=-1;
                        }
                    } else {
                        cout << "problem!!!" << endl;
                    }
                }
            }
        }

        #if 0
        for(int r=1;r<=N;r++){
            for(int c=1;c<=N;c++){
                // cout << "R" << r <<" C"<<c<< " val"        <<T[r][c]<<endl;
            }
            // cout << "R" << r << " Score:" << S[r].sc << " overall:" << S[r].ovr << endl;
        }
        #endif

        
        return S[N].ovr==1;
        
        
        
    }
};
