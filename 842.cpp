// 842. Split Array into Fibonacci Sequence
//因为返回值必须是vector<int>
//所以大于INT_MAX就返回false... -> (0 <= F[i] <= 2^31 - 1, (that is, each integer fits a 32-bit signed integer type);)
//好像有一些超过long long范围是符合要求的，但是是false--
class Solution {
public:
    vector<int> splitIntoFibonacci(string s) {
        vector<int> ans(2);
        for(int i=1;i<=s.size();i++){
            if(s[0] == '0' && i > 1)break;
            long n1 = convert(0,i,s);
            if(n1 > INT_MAX)break;
            ans[0] = n1;
            for(int j = i+1;j<=s.size();j++){
                if(s[i] == '0' && j-i>1)break;
                int left = s.size() - j;
                if(left < i || left < j-i)continue;
                // cout << convert(0,i,s)<<' '<<convert(i,j-i,s)<<'\n';
                long n2 = convert(i,j-i,s);
                if(n2 > INT_MAX)break;
                ans[1] = n2;
                
                if(recur(ans,n1,n2,j,s))return ans;
            }
        }
        return {};
    }
    
    bool recur(vector<int>& cur, long n1, long n2, int pos, string& s){
        if(pos == s.size())return true;
        
        long expect = n1+n2;
        if(s[pos] == '0' && expect != 0)return false;
        
        for(int i = pos+1;i<=s.size();i++){
            long next = convert(pos, i-pos, s);
            if(next > INT_MAX)return false;
            if(expect == next){
                cur.push_back(next);
                if(recur(cur,n2, next, i, s))return true;
                cur.pop_back();
                return false;
            }
            else if(next > expect)return false;
        }
        return false;
    }
    
    long convert(int pos, int sz, string &s){
        long ret = 0;
        for(int i=0;i<sz;i++){
            ret = (s[i+pos]-'0')+ret*10;
        }
        return ret;
    }
};