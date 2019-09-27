// 424. Longest Repeating Character Replacement
//Sliding Windows

//先划出一个窗口，尝试右移窗口的右边界
//到达极限，开始挪动左边界
class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.size() < k+1)return s.size();
        //先划出一个k大小的窗口
        int cnt[26] = {0};
        
        //也可以省掉这个前面的步骤，直接进入循环
        for(int i=0;i<k+1;i++){
            cnt[s[i] - 'A']++;
        }
        
        //
        int ans = 0;
        int start = 0;
        int max_alpha = 0;
        
        for(int i=k+1;i<s.size();){
            // cout<< i<<' ';
            if(start == 0 || max_alpha == s[start-1]-'A'){
                max_alpha = 0;
                for(int i=1;i<26;i++){
                    if(cnt[max_alpha] < cnt[i]){
                        max_alpha = i;
                    }
                }
                // max_alpha = max_element(cnt, cnt+s.size()) - cnt;
            }
            
            // cout<<max_alpha<<' ';
            while(i<s.size() && i <= cnt[max_alpha] + k + start){
                if(i == cnt[max_alpha]+k+start && cnt[s[i]-'A'] != cnt[max_alpha])break;
                if(++cnt[s[i]-'A'] > cnt[max_alpha]){
                    max_alpha = s[i]-'A';
                }
                i++;
            }
            
            ans = max(i-start, ans);
            if(i==s.size())break;
            
            
            --cnt[s[start]-'A'];
            start++;
        }
        return ans;
    }
};