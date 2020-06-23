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
    typedef ListNode LN;
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){return head;}
        if(head->next==NULL){return head;}
        
        LN* n=head;
        
        while(1){
            if(n!=NULL && n->next !=NULL){
                int actval = n->val;
                LN* next = n->next;
                int nextval = next->val;
                if(nextval == actval){
                    //delete
                    n->next=next->next;
                } else {
                    n=n->next;
                }
                
            } else {
                break;
            }
        }
        
        return head;
    }
};
