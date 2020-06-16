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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //init
        if(head==NULL){ return head;}
        
        LN* lead = head;
        LN* lag = head;
        
        for(int i=0;i<n;i++){
            lead=lead->next;
        }
        //here gap is n between lead and lag
        
        //special
        if(lead==NULL){
            head=head->next;
            return head;
        }
        
        //generic        
        while(1){
            lead=lead->next;
            if(lead==NULL){
                LN* toDel = lag->next;
                lag->next=toDel->next;
                return head;
            }
            lag=lag->next;
        }
        
        
    }
};
