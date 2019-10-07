// 524. Longest Word in Dictionary through Deleting
//我以为O(m*n)复杂度会炸呢.........

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), 
             [](const string& l, const string& r){
                 return l.size() > r.size() || 
                     (l.size() == r.size() && l < r);
             });
        for(auto & str: d){
            if(valid(s, str)){
                return str;
            }
        }
        return "";
    }
    
    bool valid(const string& s, const string& t){
        if(t.size() > s.size()){
            return false;
        }
        int pos = 0;
        for(int i=0;i<s.size() && pos < t.size();i++){
            if(s[i] != t[pos])continue;
            pos++;
        }
        
        return pos == t.size();
    }
};