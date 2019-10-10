// 60. Permutation Sequence
//迷迷糊糊做出题系列
//
class Solution {
public:
    string getPermutation(int n, int k) {
        //cnt[i]表示i位数的可能组合数
        vector<int> cnt(n);
        int val = 1;
        for(int i=0;i<n-1;i++){
            val *= (i+1);
            cnt.push_back(val);
            // cout<<cnt.back();
        }
        vector<bool> vis(n, false);
        
        string s;
        recur(cnt, 1, k, s, vis);
        return s;
    }
    
    void recur(vector<int>& cnt, int digit,int k, string & cur, vector<bool>& vis){
        if(digit == vis.size()){
            for(int i=0;i<vis.size();i++){
                if(vis[i])continue;
                cur.push_back(char(i+1+'0'));
                break;
            }
            return;
        }
        int num = 1;
        
        int cnt_ = cnt[cnt.size() - digit];
        while(k > cnt_){
            k-=cnt_;
            num++;
        }
        int i=-1;
        for(i=0;i<vis.size() && num;i++){
            if(!vis[i])num--;
        }
        cur.push_back(char(i+'0'));
        vis[i-1] = true;
        recur(cnt, digit+1,k,cur,vis);
    }
};