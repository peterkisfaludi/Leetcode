/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        
        visit(root);
        return v;
    }
    
    void visit(Node* n){
        if(n==NULL){
            return;
        }
        for(auto c:n->children){
            visit(c);
        }
        v.push_back(n->val);
    }
    
    vector<int> v;
};
