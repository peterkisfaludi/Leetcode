class Solution {
public:
    int maximalRectangle(vector<vector<char>>& M) {
        int NR = M.size();
        if(NR==0){return 0;}
        int NC = M[0].size();
        if(NC==0){return 0;}
        
        
        
        //phase 1
        vector<vector<int>> R(NR,vector<int>(NC));
        vector<vector<int>> D(NR,vector<int>(NC));
        vector<vector<int>> A(NR,vector<int>(NC));
        
        R[NR-1][NC-1] = M[NR-1][NC-1]=='1';
        D[NR-1][NC-1] = M[NR-1][NC-1]=='1';
        
        for(int r=NR-2;r>=0;--r){
            R[r][NC-1] = (M[r][NC-1]=='1');
        }
            
        for(int r=NR-1;r>=0;--r){
            for(int c=NC-2;c>=0;--c){
                if(M[r][c]=='1'){
                    R[r][c] = R[r][c+1]+1;
                }
            }
        }
        
        for(int c=NC-2;c>=0;--c){
            D[NR-1][c] = (M[NR-1][c]=='1');
        }
            
        for(int r=NR-2;r>=0;--r){
            for(int c=NC-1;c>=0;--c){
                if(M[r][c]=='1'){
                    D[r][c] = D[r+1][c]+1;
                }
            }
        }


        for(int r=0;r<NR;++r){
            for(int c=0;c<NC;++c){
                //cout << R[r][c] << ",";
            }
            //cout << endl;
        }
        //cout << endl;
        
        for(int r=0;r<NR;++r){
            for(int c=0;c<NC;++c){
                //cout << D[r][c] << ",";
            }
            //cout << endl;
        }

        //phase 2
        for(int r=0;r<NR;++r){
            for(int c=0;c<NC;++c){
                
                int minR = R[r][c];
                int maxA = 0;
                for(int i=0;i<D[r][c];++i){
                    minR = min(minR, R[r+i][c]);
                    int area = (i+1)*minR;
                    maxA = max(maxA, area);
                    if(minR>1){
                        //r2g = minR;
                        //d2g = i;
                    }
                }
                A[r][c] = maxA;
                
                
            }
        }

        int mx=0;
        //cout << "Area:" <<endl;        
        for(int r=0;r<NR;++r){
            for(int c=0;c<NC;++c){
                //cout << A[r][c] << ",";
                mx = max(mx, A[r][c]);
            }
            //cout << endl;
        }
        return mx;
    }
}; 
