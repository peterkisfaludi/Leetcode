class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        int CA[10];
        //check row
        for(int r=0;r<9;r++){
            for(int i=1;i<10;i++){
                CA[i] = 0;
            }

            for(int c=0;c<9;c++){
                char tmpC = b[r][c];
                if(tmpC=='.'){
                    continue;
                }
                int tmp=tmpC-'0';
                if(CA[tmp]!=0){
                    return false;
                }
                CA[tmp]=1;
            }
        }
        
        //check col
        for(int c=0;c<9;c++){
            for(int i=1;i<10;i++){
                CA[i] = 0;
            }
            for(int r=0;r<9;r++){
                char tmpC = b[r][c];
                if(tmpC=='.'){
                    continue;
                }
                int tmp=tmpC-'0';
                if(CA[tmp]!=0){
                    return false;
                }
                CA[tmp]=1;
            }
        }
        
        //check subbox
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){

                for(int i=1;i<10;i++){
                    CA[i] = 0;
                }
                
                for(int r=0;r<3;r++){
                    for(int c=0;c<3;c++){
                        int R=i*3+r;
                        int C=j*3+c;
                        char tmpC = b[R][C];
                        if(tmpC=='.'){
                            continue;
                        }
                        int tmp=tmpC-'0';
                        if(CA[tmp]!=0){
                            return false;
                        }
                        CA[tmp]=1;
                    }
                }
            }
        }
        return true;
    }
};
