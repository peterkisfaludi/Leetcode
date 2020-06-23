class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() == 0 || nums.size()==1 || k==0){
            return;
        }
        
        for(int i=0;i<k%nums.size();i++){
            nums.insert(nums.begin(),nums[nums.size()-1]);
            
            nums.pop_back();
        }
    }
};
