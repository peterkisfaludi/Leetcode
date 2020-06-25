/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    typedef struct {
        double sum;
        int num;
    } sum_num_t;
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> v;
        
        visit(root,0);
        
        for(int i=0;i<sn.size();i++){
            // cout << "[" << i << "]" << sn[i].sum << "   " << sn[i].num << endl;
            v.push_back(sn[i].sum/sn[i].num);
        }
        
        return v;
    }
    
    private:
    void visit(TreeNode* n, int d){
        
        if(sn.size() <= d) {
            sn.push_back({0.0,0});
        }
        sn[d].sum += n->val;
        sn[d].num += 1;
        
        if(n->left !=NULL){
            visit(n->left,d+1);
        }
        if(n->right !=NULL){
            visit(n->right,d+1);
        }
    }
    
    vector<sum_num_t> sn;
};
