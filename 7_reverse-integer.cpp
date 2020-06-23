class Solution {
public:

bool ovfMul(unsigned int acc, bool pos){
    if(acc==0){return false;}
    if(pos){
        if(acc>INT_MAX/10){return true;}
    } else {
        if(acc > -(INT_MIN/10)){return true;}
    }
    return false;
}

bool ovfAdd(unsigned int acc, bool pos, int numb){
    if(numb==0){return false;}
    if(pos){
        if(acc>INT_MAX-numb){return true;}
    } else {
        if(acc>-(INT_MIN+numb)){return true;}
    }
    return false;
}
    
int reverse(int x) {
    if(x==INT_MIN) {return 0;}
    if(x==0) {return 0;}
    bool pos = x>=0;
    
    unsigned int acc=0;
    while(x!=0){
        if(ovfMul(acc, pos)){return 0;}
        acc*=10;

        int numb = x%10;
        x/=10;
        if(!pos){numb*=-1;}
        if(ovfAdd(acc, pos, numb)){return 0;}
        acc+=numb;
    }

    return pos?acc:-acc;
}
};
