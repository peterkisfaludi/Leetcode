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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0){return NULL;}
        TN fakeRoot(-1000);
        f(nums,&fakeRoot,true);
        return fakeRoot.left;
    }
    
    private:
    void f(vector<int>& arr,TN* parent, bool left){
        int len = arr.size();
        if(len==0){return;}
        int idx = arr.size()/2;
        
        
        //middle
        TN* n = new TN(arr[idx]);
        // cout << arr[idx];
        if(left){
            parent->left=n;
        } else {
            parent->right=n;
        }
        
        //visit L
        vector<int> L(arr.begin(), arr.begin() + idx);
        
        //visit R
        vector<int> R(arr.begin() + idx+1, arr.end());
        
        f(L,n,true);
        f(R,n,false);
    }
};
