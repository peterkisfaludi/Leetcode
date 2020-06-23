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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL){
            return NULL;
        }
        
        ListNode *a = headA;
        ListNode *b = headB;
        
        int lenA=0;
        int lenB=0;
        
        while(a!=NULL){
            lenA++;
            a=a->next;
        }
        while(b!=NULL){
            lenB++;
            b=b->next;
        }
        
        a = headA;
        b = headB;
        int skip = abs(lenA-lenB);
        //skip the first few
        for(int i=0;i<skip;i++){
            if(lenA>lenB){
                a=a->next;
            } else {
                b=b->next;
            }
        }
        
        //match
        for(int i=0;i<min(lenA,lenB);i++){
            if(a==b){
                return a;
            }
            a=a->next;
            b=b->next;
            if(a==NULL || b==NULL){
                break;
            }
        }
        
        return NULL;
    }
};
