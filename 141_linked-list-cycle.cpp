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
    bool hasCycle(ListNode *head) {
        ListNode dummy_(1);
        ListNode* dummy = &dummy_;
        
        if(head==NULL){
            return false;
        }
        
        ListNode* n = head;
        while(n->next!=NULL){
            if(n->next==dummy){
                return true;
            }
            ListNode* prev = n;
            n=n->next;
            prev->next=dummy;
        }
        return false;
        
        
    }
};
