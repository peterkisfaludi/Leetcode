class Solution {
public:
    string reverseWords(string s) {
        int I=0;
        int F=0;

        while(s[F]==' '){++F;}
        int b=F; //begin
        int N=s.length();
        if(N==F){return "";}
        
        
        int e=N-1;
        while(s[e]==' '){--e;}
        s.resize(e+1);
        N=s.length();

        while(F<N){
            if(s[F]!=' '){
                s[I]=s[F];
                ++I;
                ++F;
            } else if (s[F]==' ' && (F!=0 && s[F-1]!=' ')){
                s[I]=s[F];
                ++I;
                ++F;
            } else {
                ++F;
                --e;
            }
        }
        s.resize(e-b+1);
        N=s.length();
        
        //reverse sentence
        for(int i=0;i<N/2;++i){
            char tmp=s[i];
            s[i]=s[N-1-i];
            s[N-1-i]=tmp;
        }

        //reverse words
        int B=0;
        for(F=0;F<N;++F){
            if(s[F]==' '){
                for(int i=B;i<(B+F)/2;++i){
                    char tmp=s[i];
                    s[i]=s[F-1-i+B];
                    s[F-1-i+B]=tmp;
                }
                B=F+1;
            }
        }
        
        for(int i=B;i<(B+F)/2;++i){
            char tmp=s[i];
            s[i]=s[F-1-i+B];
            s[F-1-i+B]=tmp;
        }
        
        
        return s;
        
        
    }
};
