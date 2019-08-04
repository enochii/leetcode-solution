#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <unordered_map>

using namespace std;

//滑动窗口，双指针
//当合法时尝试左移缩小窗口，不合法时右移直到合法
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> cnt;
        int left=0,right=0;
        int min_sz = s.size()+1;
        int start = -1;
        for(auto c:t){
            cnt[c]++;
        }
        //可以用一个bool数组做记忆优化...
        // vector<int> contains(s.size(), false);
        // for(int i=0;i<s.size();i++){
        //     if(cnt.find(s[i])!=cnt.end())contains[i]=true;
        // }
        //********初始化一手*********//
        bool tag = false;
        //这个t_cnt比遍历map要好用得多...
        //想法是当集齐了t中的所有字符，就算是初始化完成
        //下面的滑动窗口是用一个missed_c表示缺少字符来进行窗口的移动
        //事实上也可以用这个t_cnt来控制是左移还是右移，这样就不用有个初始化的逻辑了--
        int t_cnt = t.size();
        for(;right<s.size();right++){
            if(cnt.find(s[right])!=cnt.end()){
                if(cnt[s[right]]-->0)--t_cnt;
                if(t_cnt<=0){
                    start = 0;
                    min_sz = right+1;
                    tag = true;
                    break;
                }
            }
        }
        //*************************//
        if(!tag)return "";
        right++;
        
        char missed_c;
        //注意条件判断，合法时就算字符床已经结束也要尝试右移左指针，比如最后一个字符使得tag为true的情况
        while(left<right && right<s.size() || tag){
            if(tag){
                missed_c=s[left++];
                if(cnt.find(missed_c)!=cnt.end()){
                    // tag = (cnt[missed_c]++==0);
                    if(cnt[missed_c]++<0){
                        if(min_sz > right-left){
                            min_sz = right-left;
                            start = left;
                        }
                    }else{
                        // cout<<left-1<<' '<<right<<' ';
                        tag = false;
                    }
                }else{
                    if(min_sz>right-left){
                        min_sz = right-left;
                        start = left;
                    }
                }
            }else{
                char ch = s[right];
                right++;
                if(cnt.find(ch)!=cnt.end()){
                    if(missed_c==ch){
                      tag=true;
                    }
                    cnt[ch]--;
                }
            }
        }
        
        
        return min_sz>s.size()?"":s.substr(start, min_sz);
    }

    bool valid(unordered_map<char,int> cnt){
        for(auto c:cnt){
            if(c.second>0)return false;
        }
        return true;
    }

};