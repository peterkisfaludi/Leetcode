class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& L, vector<int>& newInterval) {
        int N = L.size();
        
        if(N==0){
            L.push_back(newInterval);
            return L;
        }
        
        if(newInterval[1] < L[0][0]){
            L.insert(L.begin(), newInterval);
            return L;
        }
        
        if(newInterval[0] > L[N-1][1]){
            L.push_back(newInterval);
            return L;
        }

        
        int B=newInterval[0];
        int E=newInterval[1];
        int X=N-1;
        for(int i=0;i<N;++i){
            if(B<L[i][0]){X=i;break;}
            if(B<=L[i][1]){X=i;B=L[i][0];break;}
        }

        int Y=0;
        for(int i=N-1;i>=0;--i){
            if(E>L[i][1]){Y=i;break;}
            if(E>=L[i][0]){Y=i;E=L[i][1];break;}
        }
        
        L.erase(L.begin()+X, L.begin()+Y+1);
        
        vector<int> tmp(2);
        tmp[0]=B;
        tmp[1]=E;
        L.insert(L.begin()+X,tmp);

        return L;
    }
};
