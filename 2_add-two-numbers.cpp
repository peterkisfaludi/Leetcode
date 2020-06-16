/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    private:
    typedef ListNode LN;
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //1 init
        LN* it1 = l1;
        LN* it2 = l2;
        LN* head = NULL;
        LN* tail = NULL;
        
        int carry=0;
        
        while(it1!=NULL || it2!=NULL){
            //2A
            int A=0;
            int B=0;
            
            if(it1==NULL){
                B=it2->val;
                it2=it2->next;
            } else if(it2==NULL){
                A=it1->val;
                it1=it1->next;
            } else {
                A=it1->val;
                B=it2->val;
                it1=it1->next;
                it2=it2->next;
            }
            
            int tmp=A+B+carry;
            if(tmp>9){
                carry=1;
                tmp=tmp%10;
            } else {
                carry=0;
            }
            
            //2B
            LN* ne = new LN(tmp);
            if(tail==NULL){
                tail=ne;
                head=ne;
            } else {
                tail->next=ne;
                tail=ne;
            }
        }
        
        //3
        if(carry>0){
            LN* ne = new LN(1);
            tail->next=ne;
        }
        
        return head;
    }
};
