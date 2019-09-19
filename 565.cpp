class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        //感觉有点环形链表的感觉
        //没有重复元素，所以形成的链表是那种真实的⚪
        //而不是会出现那种线和⚪相切！
        //所以你在环的任意点都会得到相同的长度
        //那么一个点只要访问一次就够了，访问过就标记负数--
        int ans=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0)continue;
            
            int cur=i;
            int len=0;
            while(nums[cur]>=0){
                len++;
                int next=nums[cur];
                nums[cur]=nums[cur]!=0?-nums[cur]:INT_MIN;
                cur=next;
            }
            ans=max(ans,len);
        }
        return ans;
    }
};