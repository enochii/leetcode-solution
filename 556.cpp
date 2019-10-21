//其实是next_permutation的变形题
//只是我又不会next_permutation了...
class Solution {
public:
    int nextGreaterElement(int n) {
        if(n < 10)return -1;
        //0是不用特殊处理的，因为它并不会被调到高位
        
        //nextpermutation
        vector<int> digits;
        while(n){
            digits.push_back(n % 10);
            n /= 10;
        }
        //1234 -> 4 3 2 1
        //1243 1324 1342
        
        for(int i=0;i + 1 < digits.size();i++){
            if(digits[i] > digits[i+1]){
                // cout<<i;
                int pos = 0;
                while(digits[pos] <= digits[i+1])pos++;
                // cout<<'\n'<<pos;
                swap(digits[pos], digits[i+1]);
                reverse(digits.begin(), digits.begin()+i+1);
                //
                long long res = 0;
                for(auto rit = digits.rbegin();rit != digits.rend();rit++){
                    res = res * 10 + *rit;
                }
                if(res > INT_MAX)return -1;
                return res;
            }
        }
        return -1;
    }
};