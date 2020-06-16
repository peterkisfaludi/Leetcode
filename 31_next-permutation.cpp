class Solution {
public:
    void nextPermutation(vector<int>& v) {
        int N=v.size();
        if(N==0 || N==1){
            return;
        }
        
        // starting from LSB, find a decreasing pair 
        for(int i=N-2;i>=0;i--){
            int B=v[i];
            int A=v[i+1];
            
            if(B<A){
                //who to swap v[i] with?                
                int mc = v[i+1];
                int mi = i+1;
                
                for(int j=i+2; j<N; j++){
                    if(v[j]>B){
                        //go as much to the right as possible
                        if(v[j]<=mc){
                            mc=v[j];
                            mi=j;
                        }
                    }
                    //break if v[j] is not bigger than B
                    else {
                        break;
                    }
                }
                
                // swap i with mi
                int tmp = v[i];
                v[i]=v[mi];
                v[mi]=tmp;
                
                //reverse R subarray
                for(int k=i+1;k<(N+i+1)/2;k++){
                    int p = k-(i+1);
                    int tmp=v[k];
                    v[k] = v[N-1-p];
                    v[N-1-p]=tmp;
                }
                return;
            }
        }
        
        // no decrease -> all increase or all the same
        for(int i=0;i<N/2;i++){
            int tmp=v[i];
            v[i] = v[N-1-i];
            v[N-1-i]=tmp;
        }
        
    }
};
