#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
//注意数字和字母的区别
    inline bool equals(char a, char b){      
        if(isnum(a)||isnum(b))return a==b;
        else return a == b ||
        a - b == 32 ||
        b - a == 32;
    }
    inline bool isnum(char c){
        return c>='0'&&c<='9';
    }
    inline bool isalpha(char c){
        return c >= 'a'&&c<='z' ||
        c>='A'&&c<='Z';
    }
    inline bool isalphanum(char c){
        return isalpha(c)||isnum(c);
    }
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while(i<j){
            while(!isalphanum(s[i])&&i<j)i++;
            while(!isalphanum(s[j])&&i<j)j--;
            //
            if(i>=j)break;
            if(!equals(s[i], s[j])){
                return false;
            }else{
                i++;j--;
            }
        }
        
        return true;
    }
};

int main()
{
    cout<<'a'<<" "<<'A'<<" "<<'a'-'A';
}