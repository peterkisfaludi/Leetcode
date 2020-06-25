class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        
        
        int arr[S.size()];
        
        int lastC = -1;
        int d=0;
        
        for(int i=0;i<S.size();i++){
            if(S[i] == C){
                //fill left full
                if(lastC==-1){
                    int tmp = 0;
                    for(int j=i;j>=0;j--){
                        arr[j] = tmp;
                        // cout << tmp << endl;
                        tmp++;
                    }
                }
                //fill left half
                else {
                    int tmp=0;
                    for(int j=i;j>lastC + (i-lastC)/2;j--){
                        arr[j]=tmp;
                        tmp++;
                    }
                }
                lastC = i;
                d=0;
            } else {
                d++;
                arr[i] = d;
            }
        }
        
        for(int i=0;i<S.size();i++){
            //cout << arr[i] << ",";
        }
        // cout << endl;
        
        vector<int> r;
        for(int i=0;i<S.size();i++){
            r.push_back(arr[i]);
        }
        return r;
    }
};
