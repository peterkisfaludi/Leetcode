/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

static TreeNode* head;

class Solution {
public:
typedef TreeNode TN;
    
    void visit(TN* node){
        
        if(node==NULL){return;}
        
        TN* left=node->left;
        TN* right = node->right;
        
        head->right=node; 
        
        node->left=NULL;
        head=head->right;
        //cout << head->val << endl;
        visit(left);
        visit(right);
    }
    
    void flatten(TreeNode* root) {
TN fh(0);    
        head=&fh;
        visit(root);
        
        TN* t=&fh;
        while(t!=NULL){
            //cout << t->val <<endl;
            t=t->right;
        }
    }
};
