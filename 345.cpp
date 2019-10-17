// 345. Reverse Vowels of a String
class Solution {
public:
    string reverseVowels(string s) {
        if(s.empty())return s;
        int l = 0, r = s.size() - 1;
        
        unordered_set<char> vowels;
        string vs = "aeiou";
        for(char c : vs){
            vowels.insert(c);
            vowels.insert(c+'A'-'a');
        }
        
        while(l < r){
            while(l<r && vowels.count(s[l]) == 0){
                l++;
            }
            while(l<r && vowels.count(s[r]) == 0){
                r--;
            }
            if(l == r)break;
            swap(s[l++], s[r--]);
        }
        return s;
    }
};