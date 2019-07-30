/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <cstdlib>
#include <string>
#include <queue>
#include <sstream>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//二叉树编解码
//这玩意生成的不是完全二叉树
//用队列反解还行
//另外，抄改了个from_string

//貌似强行队列比递归的时空复杂度都要好点
//44ms 34.6 MB
//28ms 25.5 MB

class _Codec {
    inline std::istringstream& get_istringstream(){
    static thread_local std::istringstream stream;
    stream.clear();
    stream.str("");
    return stream;
}

template <typename T>
inline T from_string(const std::string& s){
    auto& iss(get_istringstream());
    iss.str(s);
    T result;
    iss >> result;
    return result;
}
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        // data.reserve()
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()){
            auto node = q.front();
            if(node){
                data.append(to_string(node->val));
            }else{
                data.push_back('n');
            }
            data.push_back(' ');
            q.pop();
            if(!node)continue;
            q.push(node->left);
            q.push(node->right);
        }
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> nodes;

        int start = 0, pos = string::npos;
        while((pos=data.find_first_of(' ',start))!=string::npos){
            TreeNode* node = NULL;
            string subs = data.substr(start, pos-start);
            start = pos+1;
            if(subs[0]!='n'){
                // int val = from_string<int>(subs);
                int val = stoi(subs);
                // cout<<subs;
                node = new TreeNode(val);
            }

            nodes.push_back(node);
        }
        // for(int i=nodes.size()-1;i>0;i--){
        //     TreeNode* fa = NULL;
        //     for(int j = (i-1)/2;;j++){
        //         if(!nodes[j]){
        //             fa = nodes[j];
        //             break;
        //         }
        //     }
        //     if(i%2){
        //         fa->left=nodes[i];
        //     }else{
        //         fa->right=nodes[i];
        //     }
            
        // }

        queue<TreeNode*> q;
        int i = 0;
        q.push(nodes[i++]);
        while(i<nodes.size()&&!q.empty()){
            auto fa = q.front();
            q.pop();
            if(fa == NULL){
                continue;
            }
            fa->left = nodes[i++];
            if(i<nodes.size()){
                fa->right = nodes[i++];
            }
            q.push(fa->left);
            q.push(fa->right);
        }

        return nodes[0];
    }

    // TreeNode* helper(str)
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


//-------------------------------------//
//用递归试试...怎么能没想到呢...
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "n ";
        }
        string ret = to_string(root->val);
        ret.push_back(' ');
        auto l = serialize(root->left);
        auto r = serialize(root->right);

        return ret + l + r;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return deserialize_(data, pos);
    }

    TreeNode* deserialize_(string& data, int &pos){
        if(pos>=data.size()||data[pos] == 'n'){
            pos+=2;
            return NULL;
        }

        int space_pos = data.find(' ', pos);
        string subs = data.substr(pos, space_pos - pos);
        int val = stoi(subs);
        
        auto fa = new TreeNode(val);
        pos = space_pos+1;
        fa->left = deserialize_(data, pos);
        fa->right = deserialize_(data, pos);

        return fa;
    }
};