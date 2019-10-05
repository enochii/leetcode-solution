// 132. Palindrome Partitioning II
// DP

class Solution {
public:
    int minCut(string s) {
        //init: cut[j] = j
        //palin[i][j] == true -> i>0 cut[j] = min(cut[j], cut[i-1]+1)
        //                       i=0 cut[j] = 0
        int n = s.size();
        if(n<2)return 0;
        
        vector<vector<bool>> palin(n, vector<bool>(n, false));
        
        vector<int> cut(n, 0);
        for(int j=0;j<n;j++){
            cut[j] = j;
            for(int i = 0;i<=j;i++){
                if(s[i]==s[j] && (i+1>j-1 || palin[i+1][j-1])){
                    palin[i][j] = true;
                    if(i > 0)cut[j] = min(cut[j], 1+cut[i-1]);
                    else cut[j] = min(cut[j], 0);
                }
            }
        }
        return cut.back();
    }
};