class Solution {
public:

    bool isNum(char c){
        if(c >= '0' && c <= '9'){return true;}
        return false;
    }

    int ctoi(char c){
        return c - '0';
    }
    
    bool ovfMul(unsigned int acc, bool pos){
        if(acc==0){return false;}
        if(pos){
            if(acc>INT_MAX/10){return true;}
            return false;
        } else {
            if(acc > -(INT_MIN/10)){return true;}
            return false;
        }
    }
    
    bool ovfAdd(unsigned int acc, bool pos, int numb){
        if(numb==0){return false;}
        if(pos){
            if(acc>INT_MAX-numb){return true;}
            return false;
        } else {
            if(acc>-(INT_MIN+numb)){return true;}
            return false;
        }
    }

    int myAtoi(string str) {
        //1
        int N=str.length();
        int idx=-1;
        for(int i=0;i<N;++i){
            if(str[i]!=' '){
                idx=i;
                break;
            }
        }
        if(idx==-1){return 0;}
        
        //2
        bool pos=true;
        if(str[idx]=='+'){++idx;}
        else if(str[idx]=='-'){++idx;pos=false;}
        
        //3
        unsigned int acc=0;
        for(int i=idx;i<N;++i){
            if(!isNum(str[i])){
                break;
            }
            
            if(ovfMul(acc, pos)){return pos?INT_MAX:INT_MIN;}
            acc*=10;
            
            int numb = ctoi(str[i]);
            if(ovfAdd(acc, pos, numb)){return pos?INT_MAX:INT_MIN;}
            acc+=numb;
        }
        
        if(pos){return acc;}
        else {return -acc;}
    }
};
