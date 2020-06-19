class Solution {
public:
    unordered_map<char, vector<char>> M = {
        {'2',{'a','b','c'}},
        {'3',{'d','e','f'}},
        {'4',{'g','h','i'}},
        {'5',{'j','k','l'}},
        {'6',{'m','n','o'}},
        {'7',{'p','q','r','s'}},
        {'8',{'t','u','v'}},
        {'9',{'w','x','y','z'}},
    };
    int N;
    string L;
    vector<string> ret;
    
    vector<string> letterCombinations(string digits) {        
        N=digits.length();
        L=digits;
        ret = vector<string>();
        if(N==0){return ret;}
        bar(0,"");
        return ret;
    }
    
    void bar(int i, string sf){
        if(i==N){
            ret.push_back(sf);return;
            
        }
        
        for(char x:M[L[i]]){
            bar(i+1, sf+x);
        }
    }
};
