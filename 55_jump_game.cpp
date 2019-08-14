#include <vector>

using namespace std;

//这个贪心总感觉不太懂 真菜
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()<=1)return true;
        //只要存在某条路径到达最终索引且除最后一个索引能为0之外就必能到达终点
        //贪心的方法能避免踩到0，因为我们算的是两步

        //贪心
        //选取当前节点走两步能走到最远的方案
        //走到下一步
        //这种策略可以使得(合法的)每一个索引加上该索引的最大步数都可以穷举出来
        int cur_index=0;
        while(nums[cur_index]){
            int next_index=cur_index+nums[cur_index];
            if(next_index>=nums.size()-1){
                return true;
            }

            int max_reach=-1,max_i=-1;
            for(int step=1;step<=nums[cur_index];step++){
                int index=step+cur_index;
                if(max_reach<=index+nums[index]){
                    max_reach=index+nums[index];
                    max_i=index;
                }
            }
            cur_index=max_i;
        }
        return false;
    }
};