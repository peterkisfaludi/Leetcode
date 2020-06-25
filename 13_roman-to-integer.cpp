class Solution {
public:
    int romanToInt(string s) {
        char prev = 'E';
        int acc = 0;
        
        for(auto it = s.rbegin(); it != s.rend(); it++){
            char c = *it;
            int n = c2i(c);
            cout << n << endl;                        
            acc+=n;
            cout << "c:" << c << "prev:" << prev << endl;
            switch(c){
                case 'I':
                    if(prev == 'V' || prev=='X'){
                        acc-=2;                        
                    }
                    break;
                case 'X':
                    if (prev == 'L' || prev=='C'){
                        acc-=20;
                    }
                    break;
                case 'C':
                    if (prev == 'D' || prev=='M'){
                        acc-=200;
                    }
                    break;
            } // end switch
            
            cout << "acc:" << acc << endl;
            
            prev = c;                        
                        
        } // end for
    return  acc;
    }
    
private:
    int c2i(char c){
        switch(c){
            case 'I':
                return 1;
                            case 'V':
                return 5;

                            case 'X':
                return 10;

                            case 'L':
                return 50;

                            case 'C':
                return 100;

                            case 'D':
                return 500;
                            case 'M':
                return 1000;            
        }
        return 0;
    }
};
