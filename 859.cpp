// 859. Buddy Strings
class Solution {
    //首先计算 所有字母是否相同
    //接着比较位置即可（不匹配的位置 有且仅有两个）
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size())return false;
        
        int cnt[26]={0};
        
        //重复字母是免死金牌
        bool double_ = false;
        for(char c:A)
        {
            if(++cnt[c-'a'] == 2) double_ = true;;
        }
        
        for(char c:B)
        {
            if(--cnt[c-'a'] < 0)
            {
                return false;
            }
        }
        //
        int unmatch = 0;
        for(int i=0;i<A.size();i++)
        {
            if(A[i] != B[i])++unmatch;
        }
        
        return unmatch == 2 || (unmatch == 0 && double_);
    }
};