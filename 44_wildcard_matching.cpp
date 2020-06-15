class Solution {
public:
string rdup(string s){
    if(s.length() == 0){return s;}
    string t;
    
    char prev=s[0];
    t += prev;
    for(int i=1;i<s.length();++i){
        if(s[i]=='*' && prev=='*'){
            continue;
        } else {
            t += s[i];
        }
        prev=s[i];
    }
    return t;
}

bool foo(string s, string p) {
    int pi=0;
    int si=0;
    int star = -10;
    int match = -10;
    while(si < s.length()){
        
        if(pi == p.length()){
            if(star >= 0){
                match++;
                si=match;
                pi=star+1;
            } else {
                return false;
            }
        }
        else
        if(p[pi] == s[si] || p[pi]=='?'){
            pi++;
            si++;
        }
        else
        if(p[pi]=='*'){
            star = pi;
            match = si;
            pi++;
        }
        else
        if(p[pi] != s[si]){
            if(star >= 0){
                match++;
                si=match;
                pi=star+1;
            } else {
                return false;
            }
        }
    }
    cout << si << "  "<< pi << endl;
    if(si==s.length() && pi==p.length()){
        return true;
    }
    if(pi == p.length()-1 && p[p.length()-1]=='*'){
        return true;
    }
    return false;
}

bool isMatch(string s, string p) {
    p = rdup(p);
    return foo(s,p);
}
};
