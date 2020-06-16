class Solution {
public:
    string convert(string s, int nr) {
        if(nr==0){return s;}
        if(nr==1){return s;}        
        
        int N=s.length();
        if(nr>N){return s;}
        int m = 2*nr - 2;
        string ret ="";
        
        for(int j=0;j<N;j+=m){
            ret += s[j];
        }
        
        for(int r=1;r<nr-1;++r){
            for(int j=0;j<N+r;j+=m){
                if(j-r>=0){
                    ret+=s[j-r];
                }
                if(j+r<N){
                    ret+=s[j+r];
                }
            }
        }
        
        for(int j=m/2;j<N;j+=m){
            ret += s[j];
        }

        return ret;
    }
};
