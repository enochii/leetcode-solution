// 187. Repeated DNA Sequences

class _Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,bool> hs;
        
        vector<string> ans;
        for(int i=0;i+10<=s.size();i++){
            auto ss = s.substr(i, 10);
            if(!hs.count(ss)){
                hs.emplace(ss, false);
            }else if(!hs[ss]){
                hs[ss] = true;
                ans.emplace_back(ss);
            }
        }
        return ans;
    }
};

//编码...
//用两个bit表示一个 字母(A/C/G/T)
//10个用20个bit就可以表示，用一个int就够了，再加上hash

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        //编码 -> index(已经记录就变成-1)
        //hash还乐意用bitset
        unordered_map<int,int> hs;
        
        vector<string> ans;
        for(int i=0;i+10<=s.size();i++){
            int code = 0;
            for(int j=0;j<10;j++){
                int shift = 2 * j;
                switch(s[j+i]){
                    case 'A':
                        code |= 0;
                        break;
                    case 'G':
                        code |= (1 << shift);
                        break;
                    case 'C':
                        code |= (2 << shift);
                        break;
                    case 'T':
                        code |= (3 << shift);
                        break;
                }
            }
            if(!hs.count(code)){
                hs[code] = i;
            }else if(hs[code] != -1){
                ans.emplace_back(s.substr(hs[code], 10));
                hs[code] = -1;
            }
        }
        return ans;
    }
};