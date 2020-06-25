class Solution {
public:
    int findJudge(int N, vector<vector<int>>& T) {
        if(N==0){return -1;}
        
        auto V=vector<int>(N,0);
        auto E=vector<bool>(N,false);
        
        for(int i=0;i<T.size();i++){
            auto t=T[i];
            E[t[0]-1]=true;
            V[t[1]-1]++;
        }
        
        for(int i=0;i<N;i++){
            if(V[i]==N-1 && E[i]!=true){
                return i+1;
            }
        }
        return -1;
    }
};
