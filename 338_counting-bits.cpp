class Solution {
public:
	int cntb(int num){
		uint32_t mask=1;
		int cnt=0;
		for(uint8_t i=0;i<32;++i){
			if(num&mask){
				++cnt;
			}
			mask<<=1;
		}
		return cnt;
	}
    vector<int> countBits(int num) {
  		vector<int> ret=vector<int>(num+1);
  		for(int i=0;i<num+1;++i){
  			ret[i]=cntb(i);
  			//cout << i << "  " << ret[i] << endl;
		}
		return ret;
    }
};
