// 981. Time Based Key-Value Store

//把key映射到一个数组
//拿到get/set请求先定位到数组，二分
//插入好像又拉了性能
//其实可以做成两层map，但是 没必要
class TimeMap {
    unordered_map<string, vector<pair<int, string>> > mp;
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        auto& vals = mp[key];
        
        //找到>=自己的第一个数
        int l = 0, r = vals.size();
        while(l < r){
            int m = l+(r-l)/2;
            if(vals[m].first < timestamp){
                l = m+1;
            }else{
                r=m;
            }
        }
        
        vals.insert(vals.begin()+l, {timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto& vals = mp[key];
        
        int l = 0, r = vals.size();
        //找到<=ts的第一个value
        while(l < r){
            int m = l+(r-l)/2;
            if(vals[m].first <= timestamp){
                l = m+1;
            }else{
                r=m;
            }
        }
        
        return l==0 ? "":vals[l-1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */