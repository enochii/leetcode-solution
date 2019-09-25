/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 449. Serialize and Deserialize BST

#include <string>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//这道题和297一样，不过题目多了BST这个条件，所以你用297的做法一定过嗷
//其实这种题的一个点是你要怎么判断你不该继续读了...
//像297的一种做法就是：
//[2 1 null 3]这样的“内”null应该是必须编码的，不然会错位
//然后还要编成 [2 1 null null 3 null null]这样，whereby我们可以知道一颗子树到哪里就不该读了

//BST则允许我们不用编码null，因为我们可以利用大小来判断嗷
//这个上下边界的技巧又似曾相识了...


//艹
//一样的题嗷，我好菜
//其实一个点是怎么判断左右子树的分界点
//如果我们最下面一层的null节点都给出来，那么很好做，就是会多点string的空间

//这里第一种解法并没有利用BST的性质，我思考下嗷

int atoi(const string& str, int start, int len)
{
    int val=0;
    for(int i=0;i<len;i++){
        val=val*10+(str[start+i]-'0');
    }
    return val;
}

class _Codec {
    
public:
    // val1|val2|(null)|
    //要利用好BST的条件嗷，不过我不会嗷
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        serialize(root,ans);
        // cout<<ans<<'\n';
        return ans;
    }
    
    void serialize(TreeNode* root, string &str) {
        if(!root){
            str.append("n");
            return ;
        }
        str.append(to_string(root->val));
        str.push_back(' ');
        
        // if(root->left==root->right)return;//NO CHILD!
        
        serialize(root->left,str);
        serialize(root->right,str);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // return nullptr;
        int pos=0;
        return deserialize(data,pos);
    }
    
    TreeNode* deserialize(const string& data, int& pos) {
        // cout<<pos<<' ';
        if(data[pos]=='n'){
            pos++;
            return nullptr;
        }
        //
        int pp=pos;
        for(;pp<data.size() && data[pp]!=' ';pp++);
        int val=atoi(data,pos,pp-pos);
        pos=pp+1;
        
        auto ret= new TreeNode(val);
        ret->left=deserialize(data,pos);
        ret->right=deserialize(data,pos);
        
        return ret;
    }
};

//利用BST的条件来判断分界

class Codec {
    
public:
    // val1|val2|(null)|
    //要利用好BST的条件嗷，不过我不会嗷
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root,out);

        return out.str();
    }
    
    void serialize(TreeNode* root, ostringstream &out) {
        if(!root)return;
        out<<root->val<<' ';
        serialize(root->left,out);
        serialize(root->right,out);
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())return nullptr;
        int pos=0;
        return deserialize(data,pos,INT_MAX,INT_MIN);
    }
    
    // vector<int> buf;
    
    TreeNode* deserialize(const string& data, int& pos, int MAX, int MIN) {
        if(pos==data.size())return nullptr;
        int pp=pos;
        for(;data[pp]!=' ';pp++);
        int val=atoi(data,pos,pp-pos);
        
        //读错了值 就要吐回来
        //这里读错是需要成本的
        //当然你可以用一个vector先把所有的东东都一次性解析
        //好像想到另一种方法了！
        //可以用一个比如pair<bool,int> buf做缓冲区，就可以避免重复解析
        //但这样逻辑会变复杂不少，算了
        if(val>MAX||val<MIN)return nullptr;
        pos=pp+1;
        
        auto ret= new TreeNode(val);
        
        // if(pos!=data.size()){
        ret->left=deserialize(data,pos,val,MIN);
        ret->right=deserialize(data,pos,MAX,val);
        // }

        return ret;
    }
};

