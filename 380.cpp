#include <vector>
#include <unordered_map>

using namespace std;

//用unordered_map来(假装)快速定位
//vector来随机获取元素
class RandomizedSet {
    unordered_map<int,int> mp;
    vector<int> vec;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }
        //
        mp[val]=vec.size();
        vec.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto rm_kv=mp.find(val);
        if(rm_kv==mp.end()){
            return false;
        }
        if(vec.size()>1){
            //replace
            auto rep_kv=mp.find(vec.back());
            mp[rep_kv->first]=rm_kv->second;
            vec[rm_kv->second]=rep_kv->first;
        }
        //remove
        mp.erase(rm_kv->first);
        vec.pop_back();

        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vec[rand()%vec.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */