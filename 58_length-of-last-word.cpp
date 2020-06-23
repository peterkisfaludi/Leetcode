class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt=0;
        for(auto it=s.rbegin(); it!=s.rend(); it++){
            //cout << *it;
            if(*it==' '){
                if(cnt!=0)
                {
                    return cnt;
                }
            } else {
                cnt++;
            }
        }
        return cnt;
    }
};
