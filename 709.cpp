// 709. To Lower Case

class Solution {
public:
    string toLowerCase(string str) {
        for(char &c:str){
            if(c <= 'Z' && c >= 'A'){
                c += 'a' - 'A';
            }
        }
        return str;
    }
};