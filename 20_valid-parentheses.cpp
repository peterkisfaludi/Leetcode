class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 0){
            return true;
        }
        vector<char> stk;
        
        for(char c : s){
            //cout << s << endl;

            if(c==')'){
                if(stk.size()==0){
                    return false;
                }
                if(stk[0] == '('){
                    stk.erase(stk.begin());
                } else {
                    return false;
                }
            } else if (c==']'){
                                if(stk.size()==0){
                    return false;
                }

                if(stk[0] == '['){
                    stk.erase(stk.begin());
                } else {
                    return false;
                }                
            } else if (c=='}'){
                                if(stk.size()==0){
                    return false;
                }

                if(stk[0] == '{'){
                    stk.erase(stk.begin());
                } else {
                    return false;
                }                
            } else {
                stk.insert(stk.begin(), c);
            }
        }
        
        return stk.size() == 0;
    }
};
