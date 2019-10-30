// 848. Shifting Letters
class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        shifts.back() %= 26;
        for(int i = shifts.size(); i>1;i--){
            shifts[i-2] += shifts[i-1];
            shifts[i-2] %= 26;
        }
        
        for(int i = 0;i<S.size();i++){
            int index = S[i] - 'a';
            index += shifts[i];
            index %= 26;
            
            S[i] = 'a' + index;
        }
        return S;
    }
};