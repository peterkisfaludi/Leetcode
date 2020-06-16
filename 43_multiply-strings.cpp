class Solution {
public:
    int ctoi(char c){
        return c - '0';
    }
    
    char itoc(int i){
        return i + '0';
    }
    
    string padZero(string s, int pad){
        for(int i=0;i<pad;++i){
            s+='0';
        }
        return s;
    }
    
    string mult(string str, char d){
        if(d=='0'){
            return "0";
        }
        int carry=0;
        string t="";
        
        for(int i = str.length() -1; i>=0; --i){
            int m=ctoi(d) * ctoi(str[i]) + carry;
            int n=m%10;
            carry = m/10;
            t.insert(0,1,itoc(n));
        }
        if(carry){
            t.insert(0,1,itoc(carry));
        }
        
        return t;
    }

    string add(string str1, string str2){
        string t="";
        int p1=str1.length()-1;
        int p2=str2.length()-1;
        int carry=0;
        
        while(true){
            if(p1 < 0 && p2 < 0){
                break;
            }
            
            int A=0;
            int B=0;
            if(p1>=0){A=ctoi(str1[p1]);}
            if(p2>=0){B=ctoi(str2[p2]);}
            int acc=A+B+carry;
            int n=acc%10;
            carry = acc/10;
            t.insert(0,1,itoc(n));
            --p1;
            --p2;
        }
        if(carry){
            t.insert(0,1,itoc(carry));
        }
        //cout << str1 << " + " << str2 << "=" << t << endl;
        return t;
    }
    
    string add(vector<string> v){
        if(v.size()==0){return "0";}
        string t=v[0];
        for(int i=1;i<v.size();++i){
            t=add(t, v[i]);
        }
        return t;
    }


    string multiply(string num1, string num2) {
        int N1=num1.length();
        int N2=num2.length();
        
        if((N1==1 && num1[0]=='0') || (N2==1 && num2[0]=='0')){
            return "0";
        }
        if(N1==1 && num1[0]=='1'){
            return num2;
        }
        if(N2==1 && num2[0]=='1'){
            return num1;
        }

        
        vector<string> v;
        
        int pad = N2-1;
        for(int i=0;i<N2;++i){
            char d=num2[i];
            string t=mult(num1, d);
            t = padZero(t, pad);
            --pad;
            v.push_back(t);
        }
        
        // for(auto x:v){
        //     cout << x << endl;
        // }
        
        return add(v);
    }
};
