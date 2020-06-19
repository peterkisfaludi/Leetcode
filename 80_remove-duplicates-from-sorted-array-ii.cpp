class Solution {
public:
    bool allSame(deque<int>& fifo){
        return fifo[0]==fifo[1] && fifo[1]==fifo[2];
    }

    int removeDuplicates(vector<int>& nums) {
        int N=nums.size();
        if(N<3){return N;}
        deque<int> fifo;
        fifo.push_back(nums[0]);
        fifo.push_back(nums[1]);
        int i=2;
        int f=2;
        
        while(f<N){
            fifo.push_back(nums[f]);
            if(allSame(fifo)){
                ++f;
                fifo.pop_front();
                continue;
            }
            nums[i]=nums[f];
            ++i;
            ++f;
            fifo.pop_front();
        }
        
        return i;
    }
};
