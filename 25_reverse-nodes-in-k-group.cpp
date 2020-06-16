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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){return head;}
        if(k==1){return head;}
        
        int N=1;
        LN* n=head;
        while(n->next != NULL){
            n=n->next;
            ++N;
        }
        if(N==1){return head;}
        if(k>N){return head;}
        
        LN* B;
        LN* F;
        LN* tmp;
        LN* pnc;
        LN* nc;
        
        int gc=0;
        while(gc<N/k){
            if(gc==0){
                pnc=head;
                B=head;
                F=B->next;
                
                for(int i=0;i<k-1;++i){
                    tmp=F->next;
                    F->next=B;
                    B=F;
                    F=tmp;
                }
                head=B;
            }
            else
            {
                B=F;
                F=B->next;
                nc=B;                
                
                for(int i=0;i<k-1;++i){
                    tmp=F->next;
                    F->next=B;
                    B=F;
                    F=tmp;
                }
                pnc->next=B;
                pnc=nc;
            }
            ++gc;
        }
        //if(N%k!=0 || gc==1){pnc->next=F;}
        pnc->next=F;
        return head;
    }
};
