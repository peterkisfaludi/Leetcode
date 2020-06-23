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
    bool retval=false;
    typedef TreeNode TN;
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL){
            return false;
        }
        f(root,0,sum);
        return retval;
    }
    
    void f(TN* n, int sumTill, int sum){
        sumTill+=n->val;
        //if leaf
        if(n->left==NULL && n->right==NULL){
            if(sum==sumTill){
                retval=true;
            }
            return;
        }
        if(n->left!=NULL){
            f(n->left,sumTill,sum);
        }
        if(n->right!=NULL){
            f(n->right,sumTill,sum);
        }
    }
};
