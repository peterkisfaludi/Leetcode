class Solution {
public:
    int strStr(string haystack, string needle) {
        const int N = needle.length();
        const int H = haystack.length();
        
        if(N == 0){
            return 0;
        }
        
        if(H==0){
            return -1;
        }
        
        if(N > H){
            return -1;
        }
        
        for(int h=0;;){
            bool match = true;
            for(int n=0;n<N;n++){
                if(haystack[h+n] != needle[n]){
                    match = false;
                    break;
                }
            }
            if(match){
                return h;
            }
            if(h<(H-N)){
                h++;
            } else{
                break;
            }
        }
        return -1;
    }
};
