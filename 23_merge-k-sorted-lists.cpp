/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

typedef ListNode LN;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& H) {
        multimap<int, LN*> M;
        LN* ret = NULL;
        LN* tail = ret;

        int K = H.size();

        for(int i=0;i<K;++i){
            if(H[i] != NULL){
                M.insert(pair<int, LN*>(H[i]->val, H[i]));
                H[i] = H[i]->next;
            }
        }

        bool first=true;
        while(M.size()>0){
            if(first){
                first = false;
                ret = new LN(M.begin()->first);
                tail = ret;
            } else {
                auto tmp = new LN(M.begin()->first);
                tail->next = tmp;
                tail = tmp;
            }
            if(M.begin()->second->next != NULL){
                M.insert(pair<int, LN*>(M.begin()->second->next->val, M.begin()->second->next));
            }
            M.erase(M.begin());
        }

        return ret;
      
    }
};
