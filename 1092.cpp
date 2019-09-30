// 1092. Shortest Common Supersequence
//DP
//猜到要用LCS，没猜到各种case打我脸
// 1. 生成超串要用逆序。s1[i]=s2[j]，到某个时候l1=i, l2=j-1，不逆序会多push一个char
// 2. 要用s1[i] == s2[j]而不是dp[i+1][j+1]==dp[i][j]+1判断
//      可能存在dp[i][j]=n,dp[i][j+1]=n+1,dp[i+1][j+1]，这样到l1=i+1,l2=j+1就会出事 


class Solution {
public:
   string shortestCommonSupersequence(string str1, string str2) {
    // 1143 LCS
       vector<vector<int>> dp(str1.size()+1,vector<int>(str2.size()+1));
       for(int i=0;i<str1.size();i++){
            for(int j=0;j<str2.size();j++){
                if(str1[i] == str2[j]){
                    dp[i+1][j+1] = 1+ dp[i][j];
                }else{
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
       //顺序错了
//        int l1 = 0, l2 = 0;
//        string ans;
       
//        while(l1 < str1.size() || l2 < str2.size()){
//            char c;
//            if(l1 == str1.size()){
//                c = str2[l2++];
//            }else if(l2 == str2.size()){
//                c = str1[l1++];
//            }else if(str1[l1]==str2[l2]){
//                c = str1[l1++];l2++;
//            }else if(dp[l1+1][l2+1] ==dp[l1+1][l2]){
//                c = str2[l2++];
//            }else{
//                c = str1[l1++];
//            }
//            ans.push_back(c);
//        }
//        return ans;
        deque<char> dq;
        int l1 = str1.size(), l2 = str2.size();
        while(l1 || l2){
            char c;
            if(l1 == 0){
                c = str2[--l2];
            }else if(l2 == 0){
                c = str1[--l1];
            }else if(str1[l1-1]==str2[l2-1]){//
                c = str1[--l1]; --l2;
            }else if(dp[l1][l2] == dp[l1-1][l2]){
                c = str1[--l1];
            }else{
                c = str2[--l2];
            }
            dq.push_front(c);
        }
       return {dq.begin(),dq.end()};
   }
};