#include <vector>
#include <string>
#include <queue>

using namespace std;

//好像可以优化下
//毕竟你是在对字符串进行比较
//那么可以先排序 后面可以二分搜索(好像不太行？)

//这里说到了双向BFS，用来减少某些情况分支爆炸
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int end_pos=0;//end的下标
        for(;end_pos!=wordList.size();end_pos++){
            if(wordList[end_pos]==endWord){
                break;
            }
        }
        if(end_pos==wordList.size())return 0;
        //有点像bfs
        vector<bool> vis(wordList.size(),false);
        queue<string> q;
        q.push(beginWord);
        int ans=0;
        while(!q.empty()){
            int cur_sz=q.size();
            ans++;
            for(int i=0;i<cur_sz;i++){
                auto str=q.front();q.pop();
                // ans++;//进入下一层
                for(int i=0;i<wordList.size();i++){
                    if(vis[i])continue;
                    if(adjacent(wordList[i],str)){
                        if(i==end_pos)return ans+1;
                        vis[i]=true;
                        q.push(wordList[i]);
                    }
                }
            }
        }
        return 0;
    }

    //只能有一个字母相同
    bool adjacent(const string& s1,const string& s2)
    {
        int cnt=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]&&++cnt>=2)return false;
        }
        return cnt==1;
    }
};