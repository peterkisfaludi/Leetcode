class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.length() != B.length()){
            return false;
        }
        
        if(A.length() <=1 || B.length() <=1){
            return false;
        }
        
        int err = 0;
        int errLoc[2] = {-1,-1};
        int N = A.length();
        for(int i=0;i<A.length();i++){
            if(A[i] != B[i]){
                if(err>1){
                    return false;
                }
                errLoc[err] = i;
                err++;
            }
        }
        
        // cout << err;
        
        if(err==2)
        {
            //only chance is to swap
            if(A[errLoc[0]] == B[errLoc[1]] && A[errLoc[1]] == B[errLoc[0]]){
                return true;
            }
        }
        
        else if (err==1)
        {
            char Bx = B[errLoc[0]];
            for(int i=0;i<N;i++){
                if(i==errLoc[0]){
                    continue;
                }
                if(A[i] == Bx){
                    //can swap?
                    if(A[errLoc[0]] == B[i]){
                        return true;
                    }
                }
            }
        }
        
        else //err==0
        {
            for(int i=0;i<N-1;i++){
                for(int j=i+1;j<N;j++){
                    if(A[i] == A[j]){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
