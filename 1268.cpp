// class trie{
//     struct node{
//         node* child[26] = {NULL,};
//         //没有重复，所以不用记录 count
//         //只需要一个 bool 变量记录是否结束即可
//         //注意 bool boole 的情况
//         bool end = false;
//     };
//     node root;
// public:    
//     trie(vector<string>& products)
//     {
//         for(auto& str:products)
//         {
//             add_word(str);
//         }
//     }
    
//     void add_word(const string & word)
//     {
//         add_word(word, 0, &root);
//     }
    
//     vector<vector<string>> search_3(const string& word)
//     {
//         vector<vector<string>> ans;
//         node* cur = &root;
        
//         int i=0;
//         for(;i<word.size();i++)
//         {
//             cur = cur->child[word[i]-'a'];
//             if(!cur) 
//             {
//                 // i--;
//                 // cout << i << '\n';
//                 break;
//             }
//             ans.push_back(search_from(word, i, cur));
//         }
        
//         // -1（int） 会转成 unsigned int。。。。。。。。。。。。
//         for(;i<word.size();i++)
//         {
//             ans.push_back({});
//         }
        
//         return ans;
//     }

// private:
//     // word.substr(0, index) + 从 cur 起摘三个（）后缀
//     vector<string> search_from(const string & word, int index, node* cur)
//     {
//         vector<string> ans;
//         auto pre =word.substr(0, index+1);
        
//         int left = 3;
//         search_from(pre, cur, left, ans);
        
//         return ans;
//     }
    
//     void search_from(const string & prefix, node* cur, int &left, vector<string> &res)
//     {
//         if(!left)return;
        
//         if(cur->end)
//         {
//             res.push_back(prefix);
//             if(--left == 0)
//             {
//                 return;
//             }
//         }
        
//         for(int i=0;i<26;i++)
//         {
//             auto c = cur->child[i];
//             if(c == NULL)continue;
//             auto pre = prefix + char(i +'a');
//             search_from (pre, c, left, res);
//         }
//     }
    
//     void add_word(const string & word, int index, node* root)
//     {
//         int id = word[index] - 'a';
        
//         if(!root->child[id]) 
//         {
//             root->child[id] = new node();
//         }
//         node *child = root->child[id];
        
//         if(index == word.size()-1)
//         {
//             child->end = true;
//             return;
//         }
        
//         add_word(word, index+1, child);
//     }
// };

// class Solution {
// public:
//     vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
//     {
//         trie t(products);
//         return t.search_3(searchWord);
//     }
// };

//暴力 + 二分 好像快多了。。。

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
        const int limit = 3;
        
        sort(products.begin(), products.end());
        
        vector<vector<string>> ans;
        for(int end = 1; end <= searchWord.size(); end++)
        {
            string pre = searchWord.substr(0, end);
            
            auto it = lower_bound(products.begin(), products.end(), pre);
            
            // if(it != products.end())cout << *it <<endl;
            
            vector<string> suggested;
            for(int i=0;i<limit && products.end() - it > i;i++)
            {
                auto& str = *(it+i);
                // 不等于0则无用，相当于 startWith
                // cout << str <<' ' << pre <<'\n';
                if(str.find(pre))
                {
                    break;
                }
                suggested.push_back(str);
            }
            ans.push_back(suggested);
        }
        
        return ans;
    }
};

