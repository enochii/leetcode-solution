#include <vector>
#include <string>

using namespace std;

typedef struct trie* tptr;

struct trie{
    tptr next[26]={NULL};
    bool key=false;
};

//先把所有的单词都压进字典里
//这里有个前提是组成单词的字母被dfs的顺序和单词顺序是相同的... 所以trie的确会比较适合
//再一个要注意的是需要用一个vis数组标识是否已经访问，因为每个cell只能访问一次
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        trie dic;
        
        vector<string> ans;
        //填充字典
        for(auto& word:words){
            tptr head=&dic;
            if(word.empty()){
                ans.push_back("");
            }
            for(int i=0;i<word.size();i++){
                
                char ch=word[i];
                // cout<<ch<<' ';
                if(head->next[ch-'a']==NULL){
                    head->next[ch-'a']=new trie();
                }
                head=head->next[ch-'a'];
            }
            head->key=true;
        }

        string str("");
        vector<vector<int>> vis;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                auto ptr=(&dic)->next[board[i][j]-'a'];
                vis.assign(board.size(),vector<int>(board[0].size(),0));
                if(ptr!=NULL){
                    str.push_back(board[i][j]);vis[i][j]=1;
                    dfs(i,j,board,ptr,ans,str,vis);
                    str.pop_back();//vis[i][j]=0;

                }
            }
        }
        return ans;
    }
    //
    void dfs(int r,int c,vector<vector<char>>& board,tptr node,vector<string>& ans,string& s,vector<vector<int>>&vis){
        if(node->key){
            ans.push_back(s);
            node->key=false;
        }
        static int dir[5]={1,0,-1,0,1};
        for(int i=0;i<4;i++){
            int nr=r+dir[i],nc=c+dir[i+1];
            if(nr<0||nr>=board.size()||nc<0||nc>=board[0].size()){
                continue;
            }
            if(vis[nr][nc]==1)continue;
            //
            char ch=board[nr][nc];
            if(node->next[ch-'a']!=NULL){
                s.push_back(ch);vis[nr][nc]=1;
                dfs(nr,nc,board,node->next[ch-'a'],ans,s,vis);
                s.pop_back();vis[nr][nc]=0;
            }
        }
    }
};