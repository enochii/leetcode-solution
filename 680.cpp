// 680. Valid Palindrome II
class Solution {
public:
    bool validPalindrome(string s) {
        bool used = false;
        
        int l=0, r = s.size()-1;
        if(palin(s,l,r))return true;
        
        // cout << l <<' '<< r;
        int lc = l+1, rc = r;
        return palin(s,lc,rc) || 
            palin(s,l,--r);
    }
    
    bool palin(const string& s, int& l, int& r){
        while(l<r){
            if(s[l] != s[r])return false;
            l++, r--;
        }
        return true;
    }
};