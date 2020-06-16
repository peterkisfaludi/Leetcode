typedef long long int lli;

class Solution {
public:

    bool IsOp(string& x){
        if(x.length()!=1){return false;}
        switch(x[0]){
            case '*': return true;
            case '/':return true;
            case '+': return true;
            case '-':return true;
        }
        return false;
    }
    
    lli DoOp(lli op1, lli op2, char op){
        switch(op){
            case '*':return op1*op2;
            case '/':return op1/op2;
            case '+':return op1+op2;
            case '-':return op1-op2;
        }
        return 0;
    }

    int evalRPN(vector<string>& tokens) {
        vector<lli> st;
        for(auto& x:tokens){
            if(IsOp(x)){
                lli op1 = st[st.size()-2];
                lli op2 = st[st.size()-1];
                
                st.pop_back();
                st[st.size()-1] = DoOp(op1, op2, x[0]);
            } else {
                st.push_back(atoi(x.c_str()));
            }
        }
        return st[0];
    }
};
