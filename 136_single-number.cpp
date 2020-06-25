class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int tmp = 0;
        for(auto n:nums){
            tmp^=n;            
        }
        return tmp;
    }
};
