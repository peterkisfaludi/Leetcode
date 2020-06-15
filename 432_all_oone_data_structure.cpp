#include <list>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class AllOne {
public:
    struct LN{
        int val;
        unordered_set<string> S;
        LN(int val_, string& key_):val(val_){ S.insert(key_); }
    };
    list<LN> L;
    unordered_map<string,list<LN>::iterator> D;

    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        // cout << "----before----"<<endl;
        //  for(auto& x : L){
        //     cout << x.val << "  ";
        //     for (auto& y : x.S){
        //         cout << y << "  ";
        //     }
        //     cout << endl;
        //  }
        
        
        int newv=-1;
        list<LN>::iterator cand;
        if(D.count(key)!=0){ //existing key -> increment
            newv=D[key]->val+1;
            cand=next(D[key]);
            D[key]->S.erase(key);
            if(D[key]->S.size()==0){
                L.erase(D[key]);
            } 
        } else { // new key -> insert w/ value of 1
            newv=1;
            cand=L.begin();
        }
        
        //insert into cand or new
        LN tmp(newv, key);
        if(L.size()==0){
            D[key] = L.insert(L.end(),tmp);
        } else if(cand->val==newv){
            cand->S.insert(key);
            D[key]=cand;
        } else {
            D[key]=L.insert(cand,tmp);
        }
        // cout << "----after----"<<endl;
        //  for(auto& x : L){
        //     cout << x.val << "  ";
        //     for (auto& y : x.S){
        //         cout << y << "  ";
        //     }
        //     cout << endl;
        //  }
        
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(D.count(key)==0){return;}
        int newv=D[key]->val-1;
        
        list<LN>::iterator act = D[key];
        if(newv!=0){
            list<LN>::iterator cand = prev(D[key]);
            if(cand->val==newv){
                cand->S.insert(key);
                D[key]=cand;
            } else {
                LN tmp(newv, key);
                D[key]=L.insert(D[key],tmp);
            }
        }
        act->S.erase(key);
        if(act->S.size()==0){
            L.erase(act);
        }
        if(newv==0){D.erase(key);}
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(L.size()==0){return "";}
        return *(L.back().S.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(L.size()==0){return "";}
        return *(L.front().S.begin());
    } 
};
