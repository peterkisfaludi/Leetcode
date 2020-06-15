class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
    int N = A.size();
    
    // for(auto x:A){cout << x << endl;}
    
    for(int i=0;i<N;++i){
        while(A[i] <= N && A[i]>0 && A[i] != i+1){
            //swap i, A[i] -1
            if(A[i] == A[A[i]-1]){break;}
            int tmp = A[i];
            A[i] = A[tmp-1];
            A[tmp-1] = tmp;
        }
    }
    // cout << "---------------" << endl;
    // for(auto x:A){cout << x << endl;}
    
    for(int i=0;i<N;++i){
        if(A[i] != i+1){
            // cout << i << endl;
            return i+1;
        }
    }

    return N+1;
    }
};
