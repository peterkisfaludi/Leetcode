#include <list>
#include <vector>
#include <iostream>
using namespace std;

typedef TreeNode TN; 
class Solution {
public:
    struct LN{
        TN* n;
        bool expanded;
    };
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(root==nullptr){return ret;}
        list<LN> Q;
        Q.push_front({root,false});
        while(Q.size()>0){
            auto it=Q.begin();
            if(it->expanded){ret.push_back(it->n->val); Q.pop_front();}
            else{
                it->expanded=true;
                if(it->n->left!=nullptr){Q.insert(it,{it->n->left,false});}
                if(it->n->right!=nullptr){Q.insert(next(it), {it->n->right,false});}
            }
        }
        //for(int x:ret){ cout << x << ",";} cout << endl;
        return ret;
    }
};
