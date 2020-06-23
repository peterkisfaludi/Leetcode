class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1){
            return nums.size();
        }
        
        int prevIdx = 0;
        for(int i=1;i<nums.size();i++){
            int e = nums[i];
            if(e==nums[prevIdx]){
                nums.erase(nums.begin() + i);
                i--;
            } else {
                prevIdx = i;
            }
        }
        
        return nums.size();
    }
};
