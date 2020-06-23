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
    int minDepth(TreeNode* root) {
        if(root!=NULL){
            return v(root);
        }
        return 0;
    }
    
private:
    int v(TreeNode* n){
        
        //leaf
        if(n->left == NULL && n->right == NULL){
            return 1;
        }
        
        //only right
        if(n->left==NULL && n->right != NULL) {
            return v(n->right) + 1;
        }
        
        if(n->left!=NULL && n->right == NULL) {
            return v(n->left) + 1;
        }
        
        return min(v(n->left) , v(n->right)) + 1;
    }
};
