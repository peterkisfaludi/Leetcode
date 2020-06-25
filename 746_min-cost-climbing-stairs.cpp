class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> S(cost.size());
        S[0] = cost[0];
        S[1] = cost[1];
        
        for(int i=2;i<S.size();i++){
            S[i] = cost[i]+ min(S[i-1],S[i-2]);
        }
        return min(S[S.size()-1],S[S.size()-2]);
    }
};
