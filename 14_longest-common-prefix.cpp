class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string str = "";
        if(strs.empty()){
            return str;
        }
        bool match = true;
        int i =0;
        while(1){
            char c = strs[0][i];
            for (auto s : strs){
                char tmp;
                try {
                    tmp = s.at(i);
                    cout << tmp << endl;
                } catch (...){
                    return str;
                }
                if(tmp!=c){
                    return str;
                }
            }
            i++;
            str += c;
        }                                
    }
};
