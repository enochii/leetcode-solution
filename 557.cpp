// 557. Reverse Words in a String III
class Solution {
public:
    string reverseWords(string s) 
    {
        for(int pos = 0;pos < s.size(); pos++)
        {
            int end = pos;
            while(s[end]!=' ' && s[end])++end;
            
            int i = pos, j = end-1;
            while(i < j)
            {
                swap(s[i], s[j]);
                i++, j--;
            }
            
            pos = end;
        }
        
        return s;
    }
};