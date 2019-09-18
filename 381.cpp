#include <map>
#include <vector>


using namespace std;

//用map来存储元素到数组下标的映射
//vec存元素然后可以随机rand一个数出来
//注意这里允许重复，所以用了mmp，感觉也可以上map<int, vector>
//最后一个就是这里的删除变成swap手法啦
class RandomizedCollection {
    multimap<int,int> mmp;
    vector<int> vec;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool ret=mmp.find(val)==mmp.end();
        mmp.emplace(val,vec.size());
        vec.push_back(val);
        return ret;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto it=mmp.find(val);
        if(it==mmp.end())return false;
        //
        if(it->second==vec.size()-1){
            vec.pop_back();
            mmp.erase(it);
        }else{
            auto it_back=mmp.equal_range(vec.back());
            auto ib=it_back.first;
            for(;ib!=it_back.second;ib++){
                if(ib->second==vec.size()-1)break;
            }
            //
            ib->second=it->second;
            swap(vec.back(),vec[it->second]);
            mmp.erase(it);
            vec.pop_back();
        }
        return true;
        //
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int xi = rand()%vec.size();
        return vec[xi];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */