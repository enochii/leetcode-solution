#include <vector>
#include <set>
#include <algorithm>

using namespace std;


// 有个记忆化的思路就是把状态定义为：剩余的元素+已经成功form的数目
//事实上只要记录失败的即可
//成功的就已经就地返回了...

//我说nm，移位搞错卡nm
//还各种意淫？
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        set<pair<int,int>> fail;
        
        if(nums.empty())return false;
        long long sum=0;
        for(auto num:nums){
            sum+=num;
        }
        if(sum%4!=0)return false;
        long long target=sum/4;
        
        sort(nums.begin(),nums.end());
        // reverse(nums.begin(),nums.end());
        
        return recur(fail,0,0,nums,target);
    }

    bool recur(set<pair<int,int>>& fail,int used,int success,vector<int>& nums,long long target
    ){
        // cout<<pos<<' ';
        if(fail.count(make_pair(used,success))){
            return false;
        }
        long long total=0;
        for(int i=0;i<nums.size();i++){
            if(used&(1<<i)){
                total+=nums[i];
            }
            
        }
        bool more=false;
        if(total>0&&total%target==0){
            more=true;
        }
        //
        if(success==3)return true;
        
        int c=total/target;
        int remain=(c+1)*target-total;
        
        // int remain=(target*4-total-1)%target+1;
        // cout<<used<<' '<<total<<' '<<remain<<' '<<success<<' '<<more<<'\n';
        //
        for(int i=0;i<nums.size();i++){
            if(used&(1<<i))continue;
            if(remain<nums[i])continue;
            // if(i!=0&&nums[i]==nums[i-1])continue;
            if(recur(fail,used|(1<<i),success+more,nums,target))return true;
        }
        fail.emplace(used,success);
        return false;
    }
};

class Solution_ {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.empty())return false;
        long long sum=0;
        for(auto num:nums){
            sum+=num;
        }
        if(sum%4!=0)return false;
        long long target=sum/4;

       

        int four[4]={0};
        //行吧，排序牛逼
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        return xixi(nums,four,target,0,0);
    }

    bool xixi(vector<int>& nums,int four[],long long target,int cnt,int pos){
        if(pos==nums.size())return four[0]==four[1]&&four[1]==four[2]&&four[2]==four[3];
        for(int i=0;i<4;i++){
            if(four[i]+nums[pos]>target)continue;
            four[i]+=nums[pos];
            // if(four[i]==target){
            //     return xixi(nums,four,target,cnt+1,pos+1);
            // }
            //
            if(xixi(nums,four,target,cnt,pos+1))return true;
            four[i]-=nums[pos];
        }
        return false;
    }

   
};