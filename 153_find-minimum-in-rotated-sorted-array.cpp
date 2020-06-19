class Solution {
public:
    int findMin(vector<int>& A) {
        int N=A.size();
        if(N==0){return 0;}
        if(N==1){return A[0];}
        if(N==2){return min(A[0],A[1]);}
        if(N==3){return min(A[0],min(A[1],A[2]));}
        
        int B=0;
        int E=N-1;
        int M;
        
        while(1){
            M=B+(E-B)/2;
            
            if(E-B <= 2){
                return min(A[B],min(A[M],A[E]));
            }
            
            if(A[B] < A[M] && A[M] < A[E]){return A[B];}
            
            if(A[B]<A[M]){B=M;continue;}
            if(A[E]>A[M]){E=M;continue;}
        }
    }        
};

