class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int p=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] > nums[i+1]){
                p++;
                if(p>1){
                    return false;
                }
                
                
                //try move up i+1, can be problem @ i+2
                if(i==nums.size()-2){
                    //no problem @ i+2, 
                    continue;
                } else if(nums[i] <= nums[i+2]){
                    continue;
                } else {
                    //try push down i, can be problem @ i-1
                    if(i==0){
                        //no problem @ i-1
                        continue;
                    } else {
                        if(nums[i-1] <= nums[i+1]){
                            continue;
                        }
                    }
                }
                return false;
            }
        }
        return true;
    }
};
