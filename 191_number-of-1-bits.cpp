class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t mask = 1;
        int cnt=0;
        for (uint32_t i=0;i<32;++i){
        	if(n&mask){
        		++cnt;
			}
			mask<<=1;
		}
		return cnt;
    }
};
