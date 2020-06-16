class Solution {
    
public:
    int lengthOfLongestSubstring(string s) {
        int N=s.length();
        //0 corner cases
        if(N==0){
            return 0;
        }
        if(N==1){
            return 1;
        }
        
        //1 init
        
        int i1=0;
        int i2=0;
        int len=0;
        int L=0;
        
        unordered_map<char, int> umap;
        
        //2
        while(true){
            //2A
            while(true){
                
                if(umap[s[i2]] != 1){
                    umap[s[i2]] = 1;
                } else {
                    L=max(len,L);
                    break;
                }
                // for(auto x:umap){
                //     cout << x.first << x.second << endl;
                // }
                
                i2++;
                len++;
                cout << len << endl;
                if(i2==N){
                    L=max(len,L);
                    return L;
                }
            }
            
            //2B
            umap[s[i1]] = 0;
            len--;
            // for(auto x:umap){
            //     cout << x.first <<x.second << endl;
            // }
            cout <<len << endl;

            i1++;
            if(i1==N) {
                break;
            }
        }
        return 0;
    }
};
