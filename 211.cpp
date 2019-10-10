// 211. Add and Search Word - Data structure design
struct node{
    node* child[26] = {NULL};
    bool end = false;
};

class WordDictionary {
    node root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        //empty
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto cur = &root;
        for(int i=0;i<word.size();i++){
            int index = word[i] - 'a';
            if(cur->child[index] == nullptr){
                cur->child[index] = new node();
            }
            cur = cur->child[index];
        }
        cur->end = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, 0, &root);
    }
    
    //如果匹配成功，返回一个非空节点
    bool search(const string & word, int pos, node* cur){
        if(pos == word.size())return cur->end;
        
        if(word[pos] != '.'){
            int index = word[pos] - 'a';
            if(cur->child[index] == nullptr)return false;
            return search(word, pos+1, cur->child[index]);
        }else{
            for(int i=0;i<26;i++){
                if(cur->child[i] && search(word, pos+1,cur->child[i])){
                    return true;
                }
            }
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */