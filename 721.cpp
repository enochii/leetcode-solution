#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//用map + 并查集
//复习了下erase，睡觉
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> mp;
        vector<int> fa(accounts.size(),-1);
        for(int i=0;i<fa.size();i++){
            fa[i]=i;
        }
        //
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();){
                auto it=mp.find(accounts[i][j]);
                if(it!=mp.end()){
                    int pre_fa=find(it->second,fa);
                    int cfa=find(i,fa);
                    if(pre_fa!=cfa){
                        fa[cfa]=pre_fa;
                    }
                    auto it_=accounts[i].erase(accounts[i].begin()+j);//删除的话需要注意下
                    j=it_-accounts[i].begin();
                }else{
                    mp[accounts[i][j]]=i;
                    j++;
                }
            }
        }
        //
        // vector<vector<string>> ans;
        for(int i=0;i<fa.size();i++){
            int pa=find(i,fa);
            if(pa==i)continue;
            //
            for(int j=1;j<accounts[i].size();j++){
                accounts[pa].push_back(accounts[i][j]);
            }
            accounts[i].clear();
        }
        for(auto it=accounts.begin();it!=accounts.end();){
            if(it->empty()){
                it=accounts.erase(it);
            }else{
                sort(it->begin(),it->end());
                unique(it->begin(),it->end());
                it++;
            }
        }
        return accounts;
    }

    int find(int i, vector<int>& fa){
        return fa[i]==i?i:(fa[i]=find(fa[i],fa));
    }
};