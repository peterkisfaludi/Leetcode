class Solution {
public:
    bool canJump(vector<int>& A) {
        int N=A.size();
        if(N<2){
            return true;
        }
        
        int nd=1;
        for(int i=N-2;i>=0;--i){
            if(nd<=A[i]){
                nd=1;
            } else {
                ++nd;
            }
            
        }
        return nd==1;
    }
};
