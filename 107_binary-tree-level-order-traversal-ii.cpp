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
    typedef TreeNode TN;
    typedef TN* pTN;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // 1 init
        auto ret = vector<vector<int>>();
        auto A = vector<pTN>();
        auto B = vector<pTN>();
        vector<pTN>* act = &A;
        vector<pTN>* other = &B;
        
        if(root==NULL){return ret;}
        A.push_back(root);
        //loop
        while(A.size()>0 || B.size()>0){
            
            auto retLine = vector<int>(act->size());
            for(int i=0;i<act->size();i++){
                retLine[act->size()-1-i]=(*act)[i]->val;
            }
            ret.insert(ret.begin(),retLine);
            
            while(act->size()>0){
                // pop
                pTN n=act->back();
                
                // push kids
                if(n->left!=NULL){other->insert(other->begin(),n->left);}
                if(n->right!=NULL){other->insert(other->begin(),n->right);}
                
                //erase last
                act->pop_back();
            }
            //here act is empty -> swap buffers
            if(other==&B){
                other=&A;
                act=&B;
            } else {
                other=&B;
                act=&A;
            }
        }
        return ret;        
    }
};
