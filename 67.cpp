#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size()<b.size()){
            a.swap(b);
        }
        //
        if(b.empty())return a;
        int carry=0;
        int i,j;
        for(i=a.size()-1,j=b.size()-1;j>=0;i--,j--){
            int res=carry+(a[i]-'0')+(b[j]-'0');
            carry=(res>=2);
            a[i]=(res%2)+'0';
        }
        //b已经用完了
        for(;carry&&i>=0;i--){
            carry=a[i]-'0';
            a[i]=(1-carry)+'0';
        }
        if(carry){
            a='1'+a;
        }
        
        return a;
    }
};