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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){return head;}
        if(k==0){return head;}
        
        //measure len
        int N=0;
        LN* tmp=head;
        while(tmp != NULL){
            tmp=tmp->next;
            ++N;
        }
        k=k%N;
        if(k==0){return head;}
                
        LN* F=head;
        LN* T=head;
        LN* B=head;
        LN* B_1=head;
                
        for(int i=0;i<k;++i){
            F=F->next;
        }
        
        while(F!=NULL){
            B_1=B;
            B=B->next;
            T=F;
            F=F->next;
        }
        
        LN* newhead = B;
        T->next = head;
        B_1->next=NULL;
        head=newhead;
        
        return head;
        
    }
};
