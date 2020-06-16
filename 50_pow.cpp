class Solution {
public:

    double myInnerPow(double x, int n) {
        if(x==0.0){return 0.0;}
        if(n==0){return 1;}
        if(n==1){return x;}
        
        int r=n%2;
        double p=myInnerPow(x, n/2);
        double p2 = p*p;
        if(r==0){
            return p2;
        } else {
            return p2*x;
        }
    }
    
    double myPow(double x, int n) {
        double ret = myInnerPow(x,n);
        return n>=0?ret:1/ret;
    }
};
