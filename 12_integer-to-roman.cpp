class Solution {
public:
    string intToRoman(int num) {
        
        
        int x1000 = num/1000;
        num=num-x1000*1000;
        int x100 = num/100;
        num=num-x100*100;
        int x10 = num/10;
        num=num-x10*10;
        int x1 = num/1;
        num=num-x10*1;
        
        cout << x1000 << "  " << x100 << "  " << x10 << "  " << x1<< endl;
        
        string s="";
        
        //1000
        for(int i=0;i<x1000;i++){
            s.append("M");
        }
        
        //100
        while(1){
            if(x100==9){
                s.append("CM");
                break;
            }
            if(x100==4){
                s.append("CD");
                break;
            }
            if(x100>=5){
                s.append("D");
                x100-=5;
            }
            for(int i=0;i<x100;i++){
                s.append("C");
            }
            break;
        }
        
        //10
        while(1){
            if(x10==9){
                s.append("XC");
                break;
            }
            if(x10==4){
                s.append("XL");
                break;
            }
            if(x10>=5){
                s.append("L");
                x10-=5;
            }
            for(int i=0;i<x10;i++){
                s.append("X");
            }
            break;
        }
        
        //1
        while(1){
            if(x1==9){
                s.append("IX");
                break;
            }
            if(x1==4){
                s.append("IV");
                break;
            }
            if(x1>=5){
                s.append("V");
                x1-=5;
            }
            for(int i=0;i<x1;i++){
                s.append("I");
            }
            break;
        }


        
        return s;
    }
};
