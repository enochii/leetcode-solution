#include <string>

using namespace std;

struct node;

typedef node* nptr;

struct node{
    bool has_key = false;
    nptr ptrs[26] = {NULL};

    ~node(){
        for(auto ptr : ptrs){
            delete ptr;
        }
    }
};

class Trie {
    node root;
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    nptr preix_ptr(string word){
        auto rt = &root;
        for(int i=0;i<word.size();i++){
            int index = word[i]-'a';
            rt = rt->ptrs[index];

            if(!rt){
                break;
            }
        }
        return rt;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto rt = &root;
        for(int i=0;i<word.size();i++){
            int index = word[i]-'a';
            if(!(rt->ptrs[index])){
                rt->ptrs[index] = new node();
            }
            rt = rt->ptrs[index];
        }
        rt->has_key = true;

    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto rt = &root;
        for(int i=0;i<word.size();i++){
            int index = word[i]-'a';
            rt = rt->ptrs[index];

            if(!rt){
                return false;
            }
        }

        return rt->has_key;
        // auto ret = preix_ptr(word);
        // return ret && ret->has_key;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto rt = &root;
        for(int i=0;i<prefix.size();i++){
            int index = prefix[i]-'a';
            rt = rt->ptrs[index];

            if(!rt){
                return false;
            }
        }
        return true;
        // return preix_ptr(prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */