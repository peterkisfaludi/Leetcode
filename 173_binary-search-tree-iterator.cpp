 typedef TreeNode TN;
class BSTIterator {
public:

    deque<TN*> Q;
    void GoLeft(TN* n){
        if(n!=NULL){
            Q.push_back(n);
            GoLeft(n->left);
        }
    }

    BSTIterator(TreeNode* root) {
        Q.clear();
        GoLeft(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TN* x = Q.back();
        int retval = x->val;
        Q.pop_back();
        GoLeft(x->right);
        return retval;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        for(auto x:Q){
            //cout << "Q: " << x->val << " " <<endl;
        }
        return Q.size()>0;
    }
};
