// [1 2] [2 3]那么1 2 3 就可以看成一个并查集？
//对每个集合进行排序就ok
// 1202. Smallest String With Swaps
//Union Find

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) 
    {
        const int n = s.size();
        vector<int> fas(n);
        for(int i=0;i<n;i++)
        {
            fas[i] = i;
        }
        
        for(auto & p : pairs)
        {
            int fa1 = find(fas, p[0]);
            int fa2 = find(fas, p[1]);
            
            fas[fa1] = fa2;
        }
        
        unordered_map<int, vector<int>> mp;
        for(int i=0;i<n;i++)
        {
            int fa = find(fas, i);
            mp[fa].push_back(i);
        }
        
        const string ori = s;
        
        for(auto pair:mp)
        {
            auto &v = pair.second;
            
            auto v1 = v;
            sort(v.begin(), v.end(), [&ori](const int l, const int r){
                return ori[l] < ori[r];
            });
            
            for(int i=0;i<v1.size();i++)
            {
                s[v1[i]] = ori[v[i]];
            }
        }
        
        return s;
    }
    
    int find(vector<int>& fas, int child)
    {
        int fa = fas[child];
        return fa == child? fa : (fas[child] = find(fas, fas[child]));
    }
    
    
};