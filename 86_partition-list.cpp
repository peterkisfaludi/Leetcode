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
    ListNode* partition(ListNode* head, int x) {
        LN flh(0);
        LN fgh(0);
        
        LN* LH = &flh;
        LN* LT = LH;
        LN* GH = &fgh;
        LN* GT = GH;
        
        //scan and split to 2 lists
        while(1){
            if(head==NULL){break;}
            bool lessthan = head->val<x;
            if(lessthan){
                //insert to L
                LT->next=head;
                LT=LT->next;
            } else {
                //insert to G
                GT->next=head;
                GT=GT->next;                
            }
            
            head=head->next;
            
            if(lessthan){
                LT->next=NULL;
            } else {
                GT->next=NULL;
            }
        }
        
        LH=LH->next;
        if(LH==NULL){
            return GH->next;
        }
        
        LT->next = GH->next;
        
        return LH;
             
    }
};
