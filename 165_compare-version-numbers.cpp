class Solution {
public:
    
    void foo(string& ver, vector<int>& v){
        vector<int> dots;
        for(int i=0;i<ver.length();++i){
            if(ver[i]=='.'){
                dots.push_back(i);
            }
        }
        
        int b=0;
        for(int i=0;i<dots.size();++i){
            v.push_back(atoi(ver.substr(b, dots[i]-b).c_str() ));
            b=dots[i]+1;
        }
        v.push_back(atoi(ver.substr(b, ver.length()-b).c_str() ));
    }
    
    int compareVersion(string version1, string version2) {
        vector<int> v1;
        vector<int> v2;
        foo(version1, v1);
        foo(version2, v2);
        
        int lc=max(v1.size(), v2.size());
        for(int i=0;i<lc;++i){
            int v1a=0;
            int v2a=0;
            if(i<v1.size()){v1a=v1[i];}
            if(i<v2.size()){v2a=v2[i];}
            
            if(v1a>v2a){return 1;}
            if(v1a<v2a){return -1;}
        }
        return 0;
    }
};
