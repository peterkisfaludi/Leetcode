typedef unsigned int uint32_t;
class Solution {
public:
    int getSum(int a, int b) {
        uint32_t result=0;
        uint32_t carry=0;
        uint32_t i;
        for (i=0; i<32; ++i){
            uint32_t ba=a&1;
            uint32_t bb=b&1;
            uint32_t resb=ba^bb;
            uint32_t res=resb^carry;
            uint32_t new_carry=0;
            if(ba==1 && bb==1) { new_carry=1; }
            if(resb==1 && carry==1) { new_carry=1; }
            result|=res << i;
            a>>=1;
            b>>=1;
            carry=new_carry;
        }
        //if(carry==1){
        //    result|=1 << (i+1);
        //}
        return result;
    }
};
