class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num[2]={-1};
        int cnt[2]={0};
        //
        for(auto n:nums){
            if((cnt[0]==0||nums[0]==n)&&n!=num[1]){//最后一个条件防止cnt[0]减到0 y的一次++遗失
                cnt[0]++;
                num[0]=n;
            }else if(cnt[1]==0||num[1]==n){
                // cout<<n<<' ';
                cnt[1]++;
                num[1]=n;
            }else{
                cnt[1]--;
                cnt[0]--;
            }
            // cout<<cnt[0]<<' '<<cnt[1]<<' ';
        }
        vector<int> res;
        cnt[0]=cnt[1]=0;
        for(auto n:nums){
            if(num[0]==n){
                cnt[0]++;
            }else if(num[1]==n){
                cnt[1]++;
            }
        }
        // cout<<cnt[1]<<' '<<cnt[0]<<' ';
        if(cnt[0]>nums.size()/3)res.push_back(num[0]);
        if(cnt[1]>nums.size()/3 && num[0]!=num[1])res.push_back(num[1]);
        
        return res;
    }
};