#include <unordered_map>
#include <list>

struct node
{
    int key, val;
    node(int k, int v):key(k),val(v){}
};


using namespace std;

class LRUCache {
    list<node> lis;
    unordered_map<int, list<node>::iterator> mp;
    int cap;
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    //获取一个值，同时提高优先级
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
        int ret=mp[key]->val;
        put_front(key);
        return ret;
    }
    
    //更新一个值或者插入
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            auto it = mp[key];
            it->val=value;
            put_front(key);
        }else if(cap>0){
            cap--;
            auto it=lis.insert(lis.begin(),{key,value});
            mp[key]=it;
        }else{
            auto e=std::prev(lis.end());
            auto k_era=e->key;
            mp.erase(k_era);
            lis.erase(e);
            auto it=lis.insert(lis.begin(),{key,value});
            mp[key]=it;
        }
    }

    //提高一个节点的优先级
    //lis, mp
    void put_front(int key){
        auto it=mp[key];
        // mp.erase(key);
        auto nod=*it;
        lis.erase(it);
        it=lis.insert(lis.begin(),nod);
        mp[key]=it;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */