class Solution {
public:
    uint32_t bar(char c){
        switch(c){
            case 'A':
            return 0UL;
            case 'C':
            return 1UL;
            case 'G':
            return 2UL;
            case 'T':
            return 3UL;
        }
        return 0UL;
    }
    
    uint32_t foo(string& s, int begin){
        uint32_t acc=0;
        for(int i=0;i<10;++i){
            acc<<=2;
            acc+=bar(s[i+begin]);
        }
        return acc;
    }

    vector<string> findRepeatedDnaSequences(string s) {
       vector<string> ret;
       unordered_map<uint32_t, int> HM;
       int N=s.length();
       for(int i=0;i<N-9;++i){
           uint32_t h=foo(s, i);
           HM[h]+=1;
           if(HM[h]==2){ret.push_back(s.substr(i, 10));}
           //cout << s.substr(i, 10) << "  " << h << endl;
       }
       return ret;
    }
}; 
