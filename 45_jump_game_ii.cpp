class Solution {
    
    typedef struct {
        int nj;
        int skp;
    } SE;
    
public:
    int jump(vector<int>& A) {
        int N=A.size();
        
        if(N==1){return 0;}
        if(A[0]==0){return -1;}
        
        vector<SE> B(N);
        
        B[N-1].nj=0;
        B[N-1].skp=0;
        
        for(int i=N-2;i>=0;--i){
            if(A[i]==0){B[i].nj=-1; continue;}
            int j=i+1;
            int mxjmp = A[i];
            while(mxjmp>0 && j<N-1){
                if(B[j].nj==-1){++j; --mxjmp; continue;}
                mxjmp-=B[j].skp;
                if(mxjmp > 0){
                    j+=B[j].skp;
                }
            }
            B[i].nj = B[j].nj +1;
            B[i].skp = j-i;
        }
        
        return B[0].nj;
    }
};
