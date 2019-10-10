// 93. Restore IP Addresses
// 感觉是可以dp的？虽然tag是bk
class Solution {
    int convert(const string &s, int start, int end){
        int ret = 0;
        for(int i=start; i<end;i++){
            ret = ret*10 + (s[i] - '0');
        }
        return ret;
    }
    vector<string> ans;
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size() < 4)return ans;
        
        string cur;
        recur(0, cur, 0, s);
        return ans;
    }
    
    void recur(int cnt, string& cur, int pos, const string & s){
        if(pos == s.size()){
            if(cnt == 4)ans.push_back(cur.substr(0, cur.size()-1));
            return;
        }
        
        if((4 - cnt) * 3 < s.size() - pos || 4 - cnt > s.size() - pos)return;
        if(s[pos] == '0'){
            cur.append("0.");
            recur(cnt+1,cur,pos+1,s);
            cur.pop_back();cur.pop_back();
            return;
        }

        for(int i=pos+1;i<=s.size() && i <= pos+3;i++){
            int num = convert(s,pos,i);
            if(num > 255)break;
            cur.append(s.substr(pos, i-pos));
            cur.push_back('.');
            
            recur(cnt+1,cur,i,s);
            
            cur = cur.substr(0, cur.size()-(i-pos)-1);
        }
    }
};