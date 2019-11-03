// 767. Reorganize String
class Solution {
public:
    string reorganizeString(string S) {
        //对每一个字母来说，只要其个数小于/等于 (s.size()+1)/2 就没有问题
        const int n = S.size();
        const int maxLimit = (n+1)/2;
        
        //有点像之前的一道题
        int cnt[26] = {0,};
        for(char c:S){
            if(++cnt[c-'a'] > maxLimit)return "";
        }
        
        vector<int> index(26);
        int maxCnt = 0;
        for(int i=0;i<26;i++){
            index[i] = i;
            if(maxCnt < cnt[i]){
                maxCnt = cnt[i];
            }
        }
        
        auto cmp = [&cnt](const int l, const int r){return cnt[l] > cnt[r];};
        sort(index.begin(), index.end(), cmp);
        
        //记最多字母的出现次数为maxCnt，建立一个大小为maxCnt的vector<string>
        //按照从多到少的顺序
        //把字母循环从上到下插入即可
        vector<string> pieces(maxCnt);
        
        int pos = 0;
        for(int id:index){
            for(int i=0;i<cnt[id];i++){
                pieces[pos].push_back(char(id+'a'));
                if(++pos >= maxCnt)pos = 0;
            }
        }
        
        string ans;
        for(auto& p:pieces){
            ans.append(p);
        }
        return ans;
    }
};