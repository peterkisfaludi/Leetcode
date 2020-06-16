class Solution {
public:
    static bool myCmp(const int &A, const int &B){
        string SA=to_string(A);
        string SB=to_string(B);
        string LR = SA+SB;
        string RL = SB+SA;
        return RL<LR;
    }
    
    string largestNumber(vector<int>& nums) {
        int N=nums.size();
        if(N==0) {return "";}
        bool allZero=true;
        for(auto &n:nums){
            if(n!=0){
                allZero=false;
                break;
            }
        }
        if(allZero){
            return "0";
        }
        
        sort(nums.begin(), nums.end(), myCmp);
        
        string s="";
        for(auto &x:nums){
            // cout << x <<" ";
            s += to_string(x);
        }
        
        return s;
    }
};
