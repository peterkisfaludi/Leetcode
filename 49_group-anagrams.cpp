class Solution {
public:
    
    struct SI{
        string s;
        int i;
        bool operator < (const SI& other) const {
            return this->s < other.s;
        }
    };
    
    vector<vector<string>> groupAnagrams(vector<string>& S) {
        int N=S.size();
        vector<vector<string>> R;
        
        if(N==0){return R;}
        if(N==1){
            R.push_back(S);
            return R;
        }
        
        //2A sort letters
        auto L=S;
        for(int i=0;i<N;i++){
            sort(L[i].begin(), L[i].end());
        }
        
        // cout << "L"<<endl;
        // for(auto &l:L){
        //     cout << l << ",";
        // }
        // cout << endl << endl;
        
        //2B
        auto W=vector<SI>(N);
        
        for(int i=0;i<N;i++){
            W[i]={L[i],i};
        }
//         cout << "W presort"<<endl;
//         for(auto &w:W){
//             cout << w.s << ",";
//         }
//         cout << endl << endl;
        
        sort(W.begin(), W.end());

        // cout << "W postsort"<<endl;
        // for(auto &w:W){
        //     cout << w.s << " " << w.i << ",";
        // }
        // cout << endl << endl;
        
        //3 group
        string prev=W[0].s;
        vector<string> tmp;
        tmp.push_back(S[W[0].i]);
        
        for(int i=1;i<N;i++){
            if(W[i].s==prev)
            {
                tmp.push_back(S[W[i].i]);
            }
            else 
            {
                R.push_back(tmp);
                tmp=vector<string>();
                tmp.push_back(S[W[i].i]);
                prev=W[i].s;
            }
        }
        R.push_back(tmp);
        return R;
    }
};
