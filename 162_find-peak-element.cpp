class Solution {
public:
    int findPeakElement(vector<int>& v) {
        int N=v.size();
        if(N==0){return -1;}
        if(N==1){return 0;}
        
        int L=0;
        int R=N-1;
        
        int p1=(L+R)/2;
        int p2=p1+1;
        while(1){
            // cout << p1 << " " << p2 << endl;
            if(v[p1]<v[p2]){
                //go right
                L=p2;
                p1=(L+R)/2;
                p2=p1+1;
                //if(p2>R){
                    if(p1==R){
                        return p1;
                    }
                    //return (v[p1]>v[p2])?p1:p2;
                //}
            } else {
                //go left
                R=p1;
                p1=(L+R)/2;
                p2=p1+1;
                if(p1<=L){
                    return (v[p1]>v[p2])?p1:p2;
                }
                
            }
        }
    
    }
};
