class MyLinkedList {
private:
    typedef struct ListNode {
        int val;
        ListNode* next;
    } LN;   
    
    LN* head = NULL;
    
    LN* nodeAtIndex(int index){
        if(index<0){
            return NULL;
        }
        if(head==NULL){
            return NULL;
        }
        LN* n=head;        
        for(int i=0;i<index;i++){
            if(n==NULL){
                return NULL;
            }
            n=n->next;
        }
        return n;        
    }
    
    LN* lastNode(){
        if(head==NULL){
            return NULL;
        }
        LN* n=head;
        while(n->next != NULL){
            n=n->next;
        }
        return n;
    }
    
    int getLength(){
        if(head==NULL){
            return 0;
        }
        LN* n=head;
        int l = 1;
        while(n->next != NULL){
            n=n->next;
            l++;
        }
        return l;
    }

    
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
       head=NULL; 
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index<0){
            return -1;
        }
        LN* n = nodeAtIndex(index);
        if(n==NULL){
            return -1;
        }
        return n->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        LN* newLN = new ListNode{val,head};
        head = newLN;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        LN* tail = lastNode();
        LN* newLN = new ListNode{val,NULL};
        
        if(tail==NULL){
            head=newLN;
        } else {
            tail->next = newLN;
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index<0){
            addAtHead(val);
            return;
        }
        int len = getLength();
        if(index>len){
            return;
        }
        
        LN* newLN = new ListNode{val,NULL};
        if(index==len){
            addAtTail(val);
        } else if(index==0){
            addAtHead(val);
        } else {
            LN* newLN = new ListNode{val,nodeAtIndex(index)};
            LN* prev = nodeAtIndex(index-1);
            prev->next=newLN;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(head==NULL){
            return;
        }
        if(index < 0){
            return;
        }
        
        int len=getLength();
        if(index>=len){
            return;
        }
        
        if(index==0){
            LN* newhead = head->next;
            delete head;
            head=newhead;
        }
        
        LN* prev=nodeAtIndex(index-1);
        LN* todel=nodeAtIndex(index);
        if(prev==NULL){
            return;
        }
        if(todel==NULL){
            return;
        }
        
        prev->next=todel->next;
        delete todel;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
