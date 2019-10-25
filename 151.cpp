// 151. Reverse Words in a String
class Solution {
public:
    string reverseWords(string s) {
        string ans;
        
        int pos = s.size();
        while(pos > 0){
            while(pos > 0 && s[pos-1]==' ')pos--;
            if(pos <= 0)break;
            
            int start = pos;
            while(start > 0 && s[start-1]!=' ')start--;
            ans.append(s.substr(start, pos-start));
            ans+=' ';
            pos = start;
        }
        if(!ans.empty())ans.pop_back();
        return ans;
    }
};