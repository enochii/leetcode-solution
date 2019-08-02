#include <vector>
#include <string>
#include <stack>
#include <set>

using namespace std;

//dfs(8 ms 9.7 MB)
//先分别算出不合法的左右括号数量l r
//通过dfs枚举各种可能
//一个优化是存在连续相同括号时，只尝试删除第一个，记该结果集为S
//可以看出删除后续的会导致S的一个子集
//因为比如"((..."
//如果你选择删除2留下1不可能得到子串"..."
//得到结果后再做一次是否合法的过滤 done

class Solution {
set<string> res;

public:
    vector<string> removeInvalidParentheses(string s) {
        res.clear();
        int l=0, r=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')l++;
            else if(s[i]==')'){
                l==0?r++:l--;
            }
        }
        dfs(0,s,l,r);
        return vector<string>(res.begin(), res.end());
    }

    void dfs(int pos, string s, int l, int r){
        //已经删除了最大数量
        if(l==0&&r==0){
            if(valid(s)){
                res.insert(s);
            }
            return;
        }
        for(int i=pos;i<s.size();i++){
            if(i!=pos&&s[i]==s[i-1])continue;

            if(s[i]=='('&&l>0){
                dfs(i,s.substr(0,i)+s.substr(i+1),l-1,r);
            }
            else if(s[i]==')'&&r>0){
                dfs(i,s.substr(0,i)+s.substr(i+1),l,r-1);
            }
        }
    }

    bool valid(const string& s){
        int l=0;
        for(auto ch:s){
            if(ch=='(')l++;
            else if(ch==')')l--;
            if(l<0)return false;
        }
        
        return l==0;
    }
};

//暴力枚举(216 ms 27.6 MB)
//两种剪枝：
//最小删除字符
//当前字符串(结果的一个前缀)是否合法
class _Solution {
set<string> res;
int max_size;
public:
    vector<string> removeInvalidParentheses(string s) {
        res.clear();
        max_size = 0;
        //

        backtrack(s,0,0,"",true,0);
        backtrack(s,0,0,"",false,0);
        vector<string> ret;
        for(auto& str:res){
            ret.push_back(str);
        }
        return ret;
    }

    void backtrack(const string& s, int pos, /*stack<char> stk, */
                    int lcnt, /*int open_cnt, */
                    string cur_str, bool contains, int cur_rm){
        if(pos>=s.size()){
            if(!lcnt){
                if(max_size<cur_str.size()){
                    max_size = cur_str.size();
                }
                if(max_size==cur_str.size()){
                    res.insert(std::move(cur_str));
                }
            }
            return;
        }
        //字母好像是出现在什么地方都可？
        if(!contains){
            //doesn't contain s[pos]
            cur_rm++;
            if(cur_rm>s.size()-max_size)return;
        }
        else{
            if(s[pos]==')'){
            // while (isalpha(stk.top()))
            // {
            //     stk.pop();
            // }
                if(lcnt<=0){//生成字符串不合法
                    return;
                }
                // if(stk.top()=='('){
                    lcnt--;
                // }
            }else if(s[pos]=='('){
                // stk.push(s[pos]);
                lcnt++;
            }else{
                //alpha, do nothing
            }
            cur_str.push_back(s[pos]);
        }
        //

        backtrack(s, pos+1, lcnt, cur_str,true,cur_rm);
        backtrack(s, pos+1, lcnt, cur_str,false, cur_rm);
    }
};