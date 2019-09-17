//贪心，虽然我记得做过类似的
//不过不看tag搞不定，上了就想dp

class Solution {
public:
    int jump(vector<int>& nums) {
        const int sz=nums.size();
        if(sz<=1)return 0;
        //
        int cnt=0;
        for(int i=0;i<sz;){
            //当前能跳的最大step
            int step=nums[i];
            
            //如果尽全力跳的话
            int jumpto=i+step;
            if(jumpto>=sz-1)return cnt+1;
            
            //开始选择
            int maxreach=jumpto+nums[jumpto];//下一步至少能到达这个点
            int choice=step;
            for(int j=1;j<step;j++){
                if(maxreach<i+j+nums[i+j]){
                    choice=j;
                    maxreach=i+j+nums[i+j];
                }
            }
            cnt++;
            i+=choice;
            if(maxreach>=sz-1)return cnt+1;
        }
        return -1;
    }
};