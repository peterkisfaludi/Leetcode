class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        
        return stringify(countAndSay(n-1));
    }
    
    private:
    string stringify(string num){
        int howmany = 1;
        char what = num[0];
        string ret="";
        
        for(auto it = num.begin()+1; it!=num.end();it++ ){
            if(*it!=what){
                //output what howmany
                ret.append(to_string(howmany));
                ret.append(1,what);
                what=*it;
                howmany=1;
            } else {
                howmany++;
            }
        }
        ret.append(to_string(howmany));
        ret.append(1,what);

        return ret;
    }
    
    
};
