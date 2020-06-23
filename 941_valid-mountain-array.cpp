class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size() < 3){
            return false;
        }
        
        
        int phase = 1;
        for(int i=1;i<A.size()-1;i++){
            if(phase==1){
                //up or triangle
                if(A[i-1] < A[i]){
                    if(A[i] < A[i+1]){
                        continue;
                    }
                    else if(A[i] > A[i+1]){
                        phase=2;
                        continue;
                    }
                }
                return false;
            }
            else {
                //down
                if(A[i-1] > A[i] && A[i] > A[i+1]){
                    continue;
                }
                return false;
            }
        }
        return phase==2;
    }
};
