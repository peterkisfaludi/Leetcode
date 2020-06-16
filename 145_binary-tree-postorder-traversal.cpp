  typedef TreeNode TN;
  
  struct LE{
    TN* node;
    bool expa;
  };
  
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(root==NULL){return ret;}
        
        list<LE> Q;
        Q.push_back({root, false});
        
        while(Q.size() > 0){
            // cout << "in Q: ";
            // for(auto x:Q){
            //      cout << x.node->val << ",  ";
            // }
            cout << endl;
            LE& le = Q.back();
            if(le.expa){
                ret.push_back(le.node->val);
                Q.pop_back();
            } else {
                if(le.node->right!=NULL){
                    Q.push_back({le.node->right, false});
                }
                if(le.node->left!=NULL){
                    Q.push_back({le.node->left, false});
                }
                le.expa=true;
            }
        }
        return ret;
    }
};
