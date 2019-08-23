#include <unordered_map>

using namespace std;

//map和umap的[]在值不存在时都会 
//value-initialized (default-constructed for class types, zero-initialized otherwise)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        //
        unordered_map<int,int> cnt;
        for(auto i:nums1){
            cnt[i]++;
        }
        vector<int> ans;
        for(auto i:nums2){
            auto kv=cnt.find(i);
            if(kv!=cnt.end()){
                if(cnt[i]--==1){
                    cnt.erase(i);
                }
                ans.push_back(i);
            }
        }
        return ans;
    }
};