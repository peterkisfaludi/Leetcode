typedef ListNode LN;
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL){return head;}
        if(head->next==NULL){return head;}
        
        LN* p1=head;
        LN* p2=p1->next;
        head=p2;
        LN* lag = p1;
        
        while(p1!=NULL){
            p2=p1->next;
            if(p2!=NULL){
                lag->next = p2;
                LN* tmp = p2->next;
                p2->next=p1;
                p1->next=tmp;
                lag = p1;
                p1=tmp;
            } else { break;}
        }
        
        return head;
    }
};
