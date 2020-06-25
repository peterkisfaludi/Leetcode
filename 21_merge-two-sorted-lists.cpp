/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    vector<ListNode*> retListNodes;
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *it1 = l1;
        ListNode *it2 = l2;
        
        // cout << (it1==NULL && it2==NULL);
        
        while(!(it1==NULL && it2==NULL)){
            //both of them has val
            if(it1!=NULL && it2!=NULL){
                if((it1->val <= it2->val)){
                    //cout << it1->val;            
                    retListNodes.push_back(it1);
                    it1 = it1->next;
                } else {
                    retListNodes.push_back(it2);
                    // cout << it2->val;
                     it2 = it2->next;
                }
            } 
            //only it1 has val
            else if(it2==NULL){
                retListNodes.push_back(it1);
                // cout << it1->val;                
                it1 = it1->next;
            }
            
            //only it2 has val            
            else if(it1==NULL){
                retListNodes.push_back(it2);
                // cout << it2->val;
                it2 = it2->next;
            }
        }
        
        // cout << "finish" << retListNodes.size();
        if(retListNodes.size() == 0){
            return NULL;
        }
        
        for(int i = 0; i < retListNodes.size() - 1; i++){
            retListNodes[i]->next = retListNodes[i+1];
        }
        // cout << "for";
        return retListNodes[0];
    }
};
