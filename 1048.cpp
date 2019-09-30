// 1048. Longest String Chain
//Dynamic Programming

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        if(words.size() < 2)return words.size();
        //
        unordered_map<int,vector<int>> mp;
        
        //...排序要在前面
        sort(words.begin(),words.end(),[](const string& l, const string& r){return l.size()>r.size();});

        for(int i=0;i<words.size();i++){
            mp[words[i].size()].push_back(i);
        }
        
        //
        vector<int> dp(words.size(),1);//dp[0] = 1;最长
        for(int i=0;i<words.size();i++){
            int sz = words[i].size();
            auto it = mp.find(sz+1);
            if(it == mp.end())continue;
            //
            for(int index : it->second){
                // cout<<words[i]<<" -> "<<words[index]<<' ';
                if(isPre(words[i], words[index])){
                    // cout<<'!'<<'\n';
                    // cout<<words[i]<<' '<<words[index]<<'\n';
                    dp[i] = max(dp[i], dp[index]+1);
                }
            }
        }
        
        return *max_element(dp.begin(),dp.end());
    }
    

    
    //不要炫技--
    bool isPre(const string& pre, const string& post){
        if(pre.empty())return true;
        
        bool diff = false;
        for(int i=0;i<pre.size();i++){
            if(pre[i] == post[i+diff]){
                continue;
            }else if(diff){
                return false;
            }else{
                if(pre[i]!=post[i+1])return false;
                diff = true;
            }
        }
        return true;
    }
};