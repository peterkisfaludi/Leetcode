class Solution {
public:
    string addStrings(string num1, string num2) {
        int N1=num1.length();
        int N2=num2.length();
        int c=0;
        string ret="";
        for(int i=0;i<max(N1,N2);++i){
            int n1=0;
            int n2=0;
            if(i<N1){n1=num1[N1-1-i]-'0';}
            if(i<N2){n2=num2[N2-1-i]-'0';}
            int tmp=n1+n2+c;
            c=0;
            if(tmp>9){
                tmp-=10;
                c=1;
            }
            ret+=tmp+'0';                            
        }
        if(c>0){
            ret+=c+'0';
        }
        reverse(ret.begin(), ret.end()); 
        return ret;
    }
};
