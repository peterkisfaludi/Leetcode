class Solution {
public:
    vector<string> b;
    void f(int s, int p, string t){
        if(s==0 && p==0){b.push_back(t); t=""; return;}
        else if(s==0 && p!=0){t.append("(");f(s+1,p-1,t);}
        else if(s!=0 && p==0){t.append(")");f(s-1,p,t);}
        else{
            string t2=t;
            t.append("("); f(s+1,p-1,t);
            t2.append(")"); f(s-1,p,t2);
        }
    }
    vector<string> generateParenthesis(int n) {
        f(0,n,"");
        return b;
    }
    
};
