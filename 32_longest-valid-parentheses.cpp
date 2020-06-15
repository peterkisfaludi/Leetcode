class Solution {
public:
    int longestValidParentheses(string A) {
        int N=A.length();
        
        if(N<2){return 0;}
        vector<int>B(N);
        
        for(int i=1;i<N;++i){
            if(A[i]=='('){continue;}
            int tmp=0;
            //actual is )
            //left is (
            if(A[i-1]=='('){
                tmp=2;
                if(i>=2){
                    tmp+=B[i-2];
                }
            }
            
            //left is )
            else {
                if(B[i-1]!=0){
                    int jb = i-1-B[i-1];
                    if(jb>=0){
                        if(A[jb]=='('){
                            tmp=2+B[i-1];
                            if(jb-1>=0){
                                tmp+=B[jb-1];
                            }
                        }
                    }
                }
            }
            
            B[i]=tmp;
        }
        
        return *max_element(B.begin(), B.end());
    }
};
