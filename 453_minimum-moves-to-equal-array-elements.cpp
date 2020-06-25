class Solution {
public:
    int minMoves(vector<int>& A) {
        int N=A.size();
        int acc=0;
        int mn=*(min_element(A.begin(), A.end()));
        for(int i=0;i<N;++i){
            acc+=(A[i]-mn);
        }
        return acc;
    }
};
