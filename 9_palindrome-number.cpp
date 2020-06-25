class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        
        int num_digits = log10(x) + 1;
        if(num_digits==1){
            return true;
        }
        if(x==0){
            return true;
        }        
        
        int i = 10;
        int mul = pow(10,num_digits - 1);
        
        for(int j=0;j<num_digits/2;j++){
            //cout << "i " << i << "mul" << mul <<endl;    
            
            int L = x/mul;
            int R = x%i;
            
            //cout << "L " << L << "R" << R <<endl;
            if(L!=R){
                return false;
            }
            
            x = x % mul;
            x = x / i;
            //cout << "x " << x <<endl;
            mul/=100;
        }
        
        return true;
        
    }
};
