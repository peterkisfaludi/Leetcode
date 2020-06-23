class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        auto &f = flowerbed;
        
        if(n==0){
            return true;
        }
        
        if(f.size()==0){
            return false;
        }
        
        //1 long fb
        if(f.size()==1){
            if(n==1){
                return f[0]==0;
            } else {
                return false;
            }
        }
        
        //first one
        if(f[0] == 0 && f[1] == 0){
            f[0]=1;
            n--;
        }
        
        //last one
        if(f[f.size()-1] == 0 && f[f.size()-2] == 0){
            f[f.size()-1]=1;
            n--;
        }
        
        for(int i=1;i<f.size()-1;i++){
            if(f[i-1]==0 && f[i] == 0 && f[i+1] == 0){
                f[i]=1;
                n--;
            }
        }
        
        return n<=0;
    }
};
