class Solution {
public:
    int threeSumClosest(vector<int>& A, int target) {
        int N=A.size();
        if(N<3){return 0;}
        
        sort(A.begin(), A.end());
        
        int i0 = 0;
        int i1  =1;
        int i2 = N-1;
        
        //fix i2
        for(;i2>i1;--i2){
            int tmp = A[i0]+A[i1]+A[i2];
            if(tmp == target) {return tmp;}
            if(tmp < target){break;}
        }
        if(i2==i1){return A[i0]+A[i1]+A[i2+1];}

        //fix i1
        for(i1 = i2-1;i1>i0;--i1){
            int tmp = A[i0]+A[i1]+A[i2];
            if(tmp == target) {return tmp;}
            if(tmp < target){break;}
        }
        if(i1==i0){return A[i0]+A[i1+1]+A[i2];}

        //fix i0
        for(i0=i1-1;i0>=0;--i0){
            int tmp = A[i0]+A[i1]+A[i2];
            if(tmp == target) {return tmp;}
            if(tmp < target){break;}
        }
        if(i1==i0){return A[i0+1]+A[i1]+A[i2];}
        return A[i0]+A[i1]+A[i2];
    }
};
