#include <map>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> cnt;
        vector<int> res;

        for(int xi:nums){
            if(cnt.count(xi)==0){
                cnt[xi] = 1;
            }else{
                cnt[xi]++;
            }
            // if(cnt[xi]==k){
            //     res.push_back(xi);
            // }
        }

        

        
        priority_queue<II, vector<II>,  cmp> pq;
        for(auto &kv:cnt){
            pq.push(kv);
        }

        while(k--){
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
private:
    typedef pair<int,int> II;
    struct cmp{
        bool operator()(const II& l, const II& r){
        return l.second<r.second;
    }
    };
};