#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        make_heap(nums.begin(),nums.end());      
        sort_heap(nums.begin(),nums.end());
        int prev=nums[0];
        for(int i=1;i<nums.size();++i){
          if(nums[i]==prev){
              return prev;
          }
          prev=nums[i];
        }
        return prev;
    }
};
