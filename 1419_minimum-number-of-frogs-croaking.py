class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int arr[4];
        int mx=0;
        int nm=0;
        for(char ch : croakOfFrogs){
            switch(ch){
                case 'c':
                    ++arr[0];
                    ++nm;
                    mx=max(mx,nm);
                    break;
                case 'r':
                    if(arr[0]==0){return -1;}
                    --arr[0];
                    ++arr[1];
                    break;
                case 'o':
                    if(arr[1]==0){return -1;}
                    --arr[1];
                    ++arr[2];
                    break;
                case 'a':
                    if(arr[2]==0){return -1;}
                    --arr[2];
                    ++arr[3];
                    break;
                case 'k':
                    if(arr[3]==0){return -1;}
                    --arr[3];
                    --nm;
                    break;
                default:
                    return -1;
            }
        }
        if(nm!=0){return -1;}
        return mx;
    }
};
