class LRUCache {
public:
    int m_cap;

    struct IV{
        list<int>::iterator iter;
        int val;
    };
    unordered_map<int, IV> HM;
    list<int> RL;
    
    LRUCache(int capacity):
    m_cap(capacity)
    {
        
    }
    
    int get(int key) {
        auto it = HM.find(key);
        if(it==HM.end()){
            return -1;
        }
        
        RL.push_back(key);
        RL.erase(it->second.iter);
        HM[key].iter = prev(RL.end());
        return it->second.val;
    }
    
    void put(int key, int value) {
        if(get(key)!=-1){//item already in cache
            RL.erase(HM[key].iter);
        }else{//item not yet in cache
            if(HM.size()<m_cap){//capacity allows
            }else{//evict LRU
                HM.erase(*(RL.begin()));
                RL.erase(RL.begin());
            }
        }
        HM[key].val=value;
        RL.push_back(key);
        HM[key].iter=prev(RL.end());

    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
