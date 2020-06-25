class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> v(0);
        if(nums1.size()==0 || nums2.size()==0){
            return v;
        }
        
        map<int,int> m1;
        map<int,int> m2;
        
        for(auto i:nums1){
            m1[i]=1;
        }
        
        for(auto i:nums2){
            m2[i]=1;
        }
        
        vector<int> set1(0);
        for(auto it=m1.begin();it!=m1.end();it++){
            set1.push_back(it->first);
        }

        vector<int> set2(0);
        for(auto it=m2.begin();it!=m2.end();it++){
            set2.push_back(it->first);
        }

        auto i1=set1.begin();
        auto i2=set2.begin();
        while(i1!=set1.end() && i2!=set2.end())        {
            if(*i1==*i2){
                v.push_back(*i1);
                i1++;
                i2++;
            }
            else if(*i1<*i2){
                *i1++;
            } else {
                *i2++;
            }
        }
        
        return v;

    }
};
