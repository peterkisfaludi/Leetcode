class Solution {
public:
    vector<vector<int>> ret;
    vector<int> C;


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        C=candidates;
        int N=C.size(); 
        ret = vector<vector<int>>();
        if(N==0){return ret;}
        
        vector<int> A(N,0);
        foo(A,target,N-1);
        pretty();
        return ret;
        
    }
    
    void foo(vector<int> A, int t, int i){
        if(i<0){return;}
        if(t<0){return;}
        if(t==0){ret.push_back(A);return;}
        
        foo(A,t,i-1);
        ++A[i];
        foo(A,t-C[i],i);
    }
    
    void pretty(){
        for(int line=0;line<ret.size();++line){
            vector<int> tmp;
            for(int i=0;i<C.size();++i){
                for(int anum=0;anum<ret[line][i]; ++anum){
                    tmp.push_back(C[i]);
                }
            }
            ret[line]=tmp;
        }
    }
};
