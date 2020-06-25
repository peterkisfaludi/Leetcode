class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> r;
        
        for(auto a:A){
            if(a%2==0){
                r.insert(r.begin(),a);
            } else {
                r.push_back(a);
            }
        }
        
        return r;
    }
};
