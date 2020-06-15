class Solution {
public:
    string spacify(string& W, vector<int>& spaces){
        int p=0;
        string tmp="";
        for(int i:spaces){
            tmp+=W.substr(p, i-p+1) + " ";
            p=i+1;
        }
        return tmp.substr(0,tmp.length()-1);
    }
    
    void foo(string str, int i, vector<int> spaces, int N, string& W, unordered_map<string, int>& HM, vector<string>& ret){
        if(i>=N){return;}
        string tmp = str + W[i];
        //cout << tmp << endl;
        int x = HM.count(tmp);
        foo(tmp, i+1, spaces, N, W, HM, ret);
        if(x>0){
            // cout << "match:" << tmp << endl;
            spaces.push_back(i);
            if(i==N-1){
                ret.push_back(spacify(W, spaces));
                // cout << "wordbreak: ";
                // for(int j:spaces){
                //     cout << j << " ";
                // }
                // cout << endl;
            }
            foo("", i+1, spaces, N, W, HM, ret);
        }
    }
    
    vector<string> wordBreak(string W, vector<string>& D) {
        unordered_map<string, int> HM;
        int N=W.size();
        for(int i=0;i<D.size();++i){
            HM[D[i]]=i;
        }
        vector<string> ret;
        vector<int> sp;
        foo("", 0, sp, N, W, HM, ret);    
        return ret;
    }
};
