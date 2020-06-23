class Solution {
public:
    int N;
    vector<vector<int>> ret;
    vector<int> A;

    vector<vector<int>> permute(vector<int>& V) {
        N=V.size();
        ret = vector<vector<int>>();
        A=V;
        foo(vector<bool>(N), vector<int>());
        return ret;
    }
    
    void foo(vector<bool> T, vector<int> R){
        bool fin = true;
        for(int i=0;i<N;++i){
            if(T[i]==false){
                fin=false;
                break;
            }
        }
        if(fin){
            ret.push_back(R);
            return;
        }
        for(int i=0;i<N;++i){
            if(T[i]==false){
                auto t = T;
                auto r = R;
                t[i]=true;
                r.push_back(A[i]);
                foo(t,r);
            }
        }
    }
};
