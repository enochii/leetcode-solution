//算是总结了一个稍微有用的点吧
//一些题是一次true就行
//所以你必然不会第二次访问(无效)
//那么用个set应该就行

#include <string>
#include <vector>

using namespace std;

//memorization的反面教材
class Solution_ {
    map<vector<int>,bool> mp;
public:
    bool isInterleave(string s1, string s2, string s3) {
        //类似匹配问题，回溯？
        if(s1.size()+s2.size()!=s3.size())return false;
        return match(s1,s2,s3,0,0,0);
    }
    
    bool match(string& s1, string& s2, string& s3, int p1, int p2, int p3){
        if(mp.count({p1,p2,p3}))return false;
        
        if(p2==s2.size()){
            return mp[{p1,p2,p3}] = (s1.substr(p1)==s3.substr(p3));
        }
        
        if(p1==s1.size()){
            return mp[{p1,p2,p3}] =(s2.substr(p2)==s3.substr(p3));
        }
        
        //
        if(s1[p1]!=s3[p3]){
            if(s2[p2]!=s3[p3])return mp[{p1,p2,p3}]=false;
            return mp[{p1,p2,p3}] = match(s1,s2,s3, p1,p2+1,p3+1);
        }
        
        //s1和s3下一个相等
        if(s2[p2]!=s3[p3]){
            return mp[{p1,p2,p3}] = match(s1,s2,s3,p1+1,p2,p3+1);
        }
        
        return mp[{p1,p2,p3}]= (match(s1,s2,s3, p1,p2+1,p3+1) ||  match(s1,s2,s3,p1+1,p2,p3+1));
    }
};


//DP本质上没有状态方程就可以记忆化嗷，数组或者map之类都可以
//不过就没办法滚动了，不过map也是稀疏的嗷 
//内存占用有点高嗷 13MB
class Solution{
    typedef tuple<int,int,int> Key;//可以换成pair
    set<Key> st;
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())return false;
        return match(s1,s2,s3,0,0,0);
    }
    //p1 + p2 = p3，所以一个状态可以用p1 p2 来标识
    bool match(string& s1, string& s2, string& s3, int p1, int p2, int p3){
        auto tup = Key({p1,p2,p3});
        //只访问一次嗷
        if(st.count(tup))return false;
        st.insert(tup);
        if(p2==s2.size()){
            return s1.substr(p1)==s3.substr(p3);
        }
        
        if(p1==s1.size()){
            return s2.substr(p2)==s3.substr(p3);
        }
        
        //
        if(s1[p1]!=s3[p3]){
            if(s2[p2]!=s3[p3])return false;
            return match(s1,s2,s3, p1,p2+1,p3+1);
        }
        
        //s1和s3下一个相等
        if(s2[p2]!=s3[p3]){
            return match(s1,s2,s3,p1+1,p2,p3+1);
        }
        
        return match(s1,s2,s3, p1,p2+1,p3+1) ||  match(s1,s2,s3,p1+1,p2,p3+1);
    }
};

//DP 嗷
//还可以滚动下
//dp[i][j]表示s1的前i个字符和s2的前j个字符可以和s3的前(i+j)个字符匹配
class Solution{
    
public:
    bool isInterleave(string s1, string s2, string s3) {
        int sz1 = s1.size(), sz2 = s2.size(), sz3 = s3.size();

        if(sz1+sz2!=sz3)return false;
        
        vector<vector<bool>> dp(sz1+1,vector<bool> (sz2+1,false));
        dp[0][0]=true;
        for(int i=0;i<sz2;i++){
            dp[0][i+1]=dp[0][i] && s2[i] == s3[0+i];
            if(dp[0][i+1]==false)break;
        }
        for(int i=0;i<sz1;i++){
            dp[i+1][0] = dp[i][0] && s1[i] == s3[i];
            for(int j=0;j<sz2;j++){
                //
                if((dp[i][j+1] && s1[i]==s3[i+j+1]) || (dp[i+1][j] && s2[j]==s3[i+j+1])){
                    dp[i+1][j+1] = true;
                }
            }
        }
        
        // for(int i=0;i<sz1+1;i++){
        //     for(int j=0;j<sz2+1;j++){
        //         cout<<dp[i][j]<<' ';
        //     }
        //     cout<<'\n';
        // }

        return dp.back().back();
    }
};