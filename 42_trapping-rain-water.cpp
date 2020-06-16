class Solution {
public:
    struct SE{
        int h;
        int w;
    };

    int trap(vector<int>& height) {
        int N=height.size();
        if(N<=2){return 0;}
        vector<SE> S = {{height[0], 1}};      
        int W=0;
        
        for(int i=1;i<N;++i){
            if(height[i]<S.back().h){
                S.push_back({height[i], 1});
            } else {
                int acc=0;
                int tmpw=1;
                SE curr = {height[i], 1};
                SE front = S.front();
                while(S.size()>0){
                    auto& back = S.back();
                    if(curr.h > back.h){
                        acc+=(curr.h - back.h)*back.w;
                        tmpw+=back.w;
                        S.pop_back();
                    } else if(curr.h == back.h){
                        W+=acc;
                        back.w+=tmpw;
                        break;
                    } else {
                        curr.w=tmpw;
                        W+=acc;
                        S.push_back(curr);
                        break;
                    }
                }
                
                if(S.size()==0){
                    acc -= (curr.h - front.h)*(tmpw-1);
                    W+=acc;
                    S.push_back(curr);
                }
            }
        }
        return W;
    }
};
