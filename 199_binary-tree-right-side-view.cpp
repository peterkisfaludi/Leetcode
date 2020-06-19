/**
 * Definition for a binary   node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



class Solution {
public:
    typedef TreeNode TN;
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        vector<TN*> Q0;
        vector<TN*> Q1;
        vector<TN*>* pQ = &Q0;
        
        if(root==NULL){
            return ret;
        }
        pQ->push_back(root);
                
        while(true){
            if(pQ->size() == 0){return ret;}
            ret.push_back(pQ->back()->val);
            
            vector<TN*>* npQ = (pQ==&Q0)?&Q1:&Q0;
            for(auto& x: *pQ){
                if(x->left != NULL){
                    npQ->push_back(x->left);
                }
                if(x->right != NULL){
                    npQ->push_back(x->right);
                }
            }
            pQ->clear();
            pQ=npQ;
        }
    }
};
