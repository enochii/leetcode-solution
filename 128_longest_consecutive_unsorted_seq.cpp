#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//tmd，每次都默认hash一类是常数时间

//用umap去存以每个数字开始的最大长度
//当一个数i第一次被i-1计算所用到时，我们事实上不需要存i开始的最大长度，因为我们再也不需要了！！！，所以我们可以填1表示已经访问
//如果我们是先算i再算i-1，那就会在while里面直接用i的结果
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int num:nums){
            mp[num]=0;
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int cur=nums[i];
            if(mp[cur]!=0)continue;//cur之后的连续数都被访问过了，不会再被需要
            int len=1;
            while(mp.find(cur+1)!=mp.end()){
                auto xi=mp[cur+1];
                if(xi!=0){
                    len+=xi;break;
                }
                cur++;
                len++;
                mp[cur]=1;
            }
            mp[nums[i]]=len;
            ans=max(len,ans);
        }
        return ans;
    }
};