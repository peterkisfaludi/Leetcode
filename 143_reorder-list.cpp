typedef ListNode LN;
class Solution {
public:
    void reorderList(ListNode* h ) {
        if(h==NULL){return;}
        if(h->next==NULL){return;}
        if(h->next->next==NULL){return;}
        
        //1 get len
        int N=1;
        LN* a = h;
        while(a->next!=NULL){
            a=a->next;
            ++N;
        }
        // cout << "len"<<N<<endl;
        LN* t=a;
        a=h;
        LN* m;
        LN* m1;
        
        //2 get middle
        for(int i=0;i<N/2 -1;++i){
            a=a->next;
        }
        m1=a;
        m=m1->next;
        // cout << "mid-1"<<m1->val<<endl;
        // cout << "mid"<<m->val<<endl;
        
        //3 cut between middle-1 and middle
        m1->next=NULL;
        
        //4 reverse list from middle till tail
        LN* p=m;
        a=m->next;
        m->next=NULL;
        while(a!=NULL){
            LN* s=a->next;
            a->next=p;
            p=a;
            a=s;
        }
        
        // cout << "head till m1"<<endl;
        // LN* it=h;
        // while(it!=NULL){
        //     cout << it->val << "  ";
        //     it=it->next;
        // }
        // cout << endl;
        // cout << "tail till m"<<endl;
        // it=t;
        // while(it!=NULL){
        //     cout << it->val << "  ";
        //     it=it->next;
        // }
        // cout << endl;

        
        //5 reorder list
        LN* left=h;
        LN* right=t;
        while(true){
            LN* ln=left->next;
            left->next = right;
            left=ln;
            if(left==NULL){break;}
            LN* rn=right->next;
            right->next=left;
            right=rn;
        }
    }
};
