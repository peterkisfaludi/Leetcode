class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = false;
        
        digits[digits.size() - 1]++;
        if(digits[digits.size() - 1]>9){
            carry = true;
            digits[digits.size() - 1]=0;
        }
        
        for(auto it = digits.rbegin() + 1; it != digits.rend(); it++){
            cout << *it << endl;
            
            if(carry){
                (*it)++;
                carry = false;
            }
            
            
            if(*it > 9){
                carry = true;
                *it = 0;
            }
        }
        
        
        if(carry){
            digits.insert(digits.begin(),1);
        }
    return digits;
    }
};
