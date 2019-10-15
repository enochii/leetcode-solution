//6 ZigZag Conversion
class _Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1)return s;
        vector<string> strs(min((int)s.size(), numRows));
        
        int pos = 0;
        bool down = true;
        for(int row=0;pos < s.size();pos++){
            strs[row].push_back(s[pos]);
            
            row += down?1:-1;
            if(row == 0 || row == strs.size()-1){
                down = !down;
            }
        }
        
        string ret;
        for(auto& str:strs){
            ret += str;
        }
        return ret;
    }
};

class Solution {
public:
    string convert(string s, int numRows) {
        
        numRows = min (numRows, (int)s.size());
        
        if(numRows <= 1)return s;
        
        string ret;
        int cycle = 2 * numRows - 2;
        for(int i=0;i<s.size();i+=cycle){
            ret += s[i];
        }
        for(int i=1;i<numRows-1;i++){
            int j=i;
            int step = cycle - 2*i;
            
            while(j < s.size()){
                ret+=s[j];                
                if(j+step >= s.size())break;
                ret += s[j+step];
                //iteration
                j+=cycle;
            }
        }
        for(int i=0;i+numRows-1<s.size();i+=cycle){
            ret += s[i+numRows-1];
        }
        
        return ret;
    }
};

