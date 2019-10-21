
class Solution {

// 520. Detect Capital
    public:
    bool detectCapitalUse(string word) {
        if(word.size() < 2)return true;
        
        // bool upper = word[0] >= 'A' && word[0] <= 'Z';
        bool upper = isupper(word[0]);
        int i= 1;
        if(upper) {
            upper = isupper(word[1]);
            i++;
        }
        if(upper){
            for(; i < word.size(); i++){
                if (!isupper(word[i]))return false;
            }
        }else{
            for(; i < word.size(); i++){
                if (isupper(word[i]))return false;
            }
        }
        
        
        return true;
    }
};