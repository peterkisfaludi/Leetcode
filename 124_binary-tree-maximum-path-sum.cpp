  typedef TreeNode TN;
  
class Solution {
public:
    void visit(TN* node, int level, vector<vector<TN*>>& L){
        if(node==NULL){return;}
        if(L.size() < level+1){
            vector<TN*> tmp;
            L.push_back(tmp);
        }
        L[level].push_back(node);
        visit(node->left, level+1, L);
        visit(node->right, level+1, L);
    }

    int maxPathSum(TreeNode* root) {
        //1 
        vector<vector<TN*>> L;
        visit(root, 0, L);
        
        //2
        int GM=root->val;
        for(int i=L.size()-1; i>=0; --i){
            for(int j=0; j<L[i].size(); ++j){
                int left=0;
                int right=0;
                int pg=0;
                TN* node=L[i][j];
                if(node->left !=NULL && node->left->val > 0) {left=node->left->val;}
                if(node->right !=NULL && node->right->val > 0) {right=node->right->val;}
                
                if(left>right){
                    pg = left;
                } else {
                    pg = right;
                }
                
                int cherry = left+right+node->val;
                GM = max(GM, cherry);
                node->val += pg;
            }
        }
        return GM;
    }
};
