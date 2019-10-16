// 541. Reverse String II
class Solution {
public:
    string reverseStr(string s, int k) {
        const int sz = s.size();
        for(int i=0;i<sz;i+=2*k){
            int rlen = min(sz, k+i);
            reverse(s.begin()+i, s.begin()+rlen);
        }
        return s;
    }
};