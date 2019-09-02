#include <string>
#include <unordered_map>

using namespace std;

//主要是循环小数的判断
//手工模拟，然后用map去判断是不是出现了循环
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0)return "0";
        // if(denominator==0)return "";
        long long num=numerator;
        long long den=denominator;
        num=abs(num);
        den=abs(den);
        //
        string ans=to_string(num/den);
        if(num%den!=0){
            ans.push_back('.');
        }
        num%=den;
        //用map来判断是否出现了循环小数
        unordered_map<int,int> mp;
        string demical="";
        int index=0;
        while(num!=0 &&mp.find(num)==mp.end()){
            mp[num]=index++;
            num*=10;
            int res=num/den;
            demical.push_back(res+'0');
            num=num%den;
        }
        //
        if(num!=0){
            //出现了循环小数
            int num_i=mp[num];
            ans.append(demical.substr(0,num_i));
            ans.push_back('(');
            ans.append(demical.substr(num_i));
            ans.push_back(')');
        }else{
            ans.append(demical);
        }
        if(numerator>0&&denominator<0||
            numerator<0&&denominator>0){
                ans='-'+ans;
            }
        return ans;
    }
};