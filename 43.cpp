#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//Big Integer -- debug有点难，吃饭吗
//感觉空间还有得优化，可以减少不必要的复制(Add,Mul的两个重载版本)

//进位问题
//转化成string记得补0

int convert(const string& s, int start, int len);

//实现加法、乘法
class Integer{
public:
    // static 
    static const int MAX_VAL = 10000;
    static const int MAX_BIT = 4;
    // -(INT_MIN / 2); 
    //stored by reversed order
    vector<int> bits;
public:
    //s不会为0？
    explicit Integer(const string& s=""){
        // cout<<s<<'\n';
        for(int i=s.size();i>0;i-=MAX_BIT){
            int high = max(i-MAX_BIT, 0);
            int one = convert(s,high,i-high);
            // cout<<one<<'\n';
            bits.push_back(one);
        }
    }

    static Integer Add(const Integer& l, const Integer& r){
        Integer ret = l;
        auto& bits = ret.bits;
        int carry = 0;
        int i=0;
        // cout<<'!';
        for(;i<r.bits.size()&&i<bits.size();i++){
            int sum = r.bits[i]+bits[i]+carry;
            carry = sum / MAX_VAL;
            bits[i] = sum % MAX_VAL;
        }
        //
        while (i<bits.size()&&carry)
        {
            bits[i] += carry;
            carry = bits[i] / MAX_VAL;
            bits[i] %= MAX_VAL;
            i++;
        }
        
        while (i<r.bits.size())
        {
            int res = r.bits[i]+carry;
            carry = res / MAX_VAL;
            res %= MAX_VAL;
            bits.push_back(res);
            i++;
        }
        if(carry){
            bits.push_back(carry);
        }
        
        return ret;
    }

    static Integer Mul(const Integer& l, const Integer& r){
        Integer ret;
        const int sz = r.bits.size();
        for(int i=sz-1;i>=0;i--){
            ret = Add(Mul(ret, MAX_VAL),Mul(l,r.bits[i]));
        }
        return ret;
    }
    //multiply Interger with a bit
    static Integer Mul(const Integer& l,int bit){
        Integer ret=l;//加()会被认为是声明!
        auto& bits = ret.bits;

        int carry = 0;
        for(int i=0;i<l.bits.size();i++){
            int res = carry + bit*l.bits[i];
            bits[i] = res % MAX_VAL;
            carry = res / MAX_VAL;
        }

        if(carry){
            bits.push_back(carry);
        }
        // cout<<ret.to_string()<<' ';
        return ret;
    }

    string to_string(){
        string ret;
        for(int i=bits.size();i>0;i--){
            auto bit = std::to_string(bits[i-1]);
            int bitsz = bit.size();
            
            if(i!=bits.size())
                for(int j=0; j< MAX_BIT - bitsz;j++){
                    bit.insert(bit.begin(),'0');
                }
            ret.append(bit);
        }
        return ret;
    }
};

class Solution {
public:
    string multiply(string num1, string num2) {
        //没有前导0
        if(num1[0] == '0' || num2[0] == '0')return "0";
        //
        Integer l(num1), r(num2);
        Integer pro = l.Mul(l,r);

        return pro.to_string();
    }
};

int convert(const string& s, int start, int len){
    int ret = 0;
    for(int i=0;i<len;i++){
        // cout<<ret<<'!';
        ret=ret*10+s[start+i]-'0';
    }

    return ret;
}

// int main()
// {
//     Integer i("1234444444"), j("2");
//     i = i.Mul(i,j);
//     cout<<i.to_string()<<'\n';
//     for(int num:i.bits){
//         // cout<<num<<' ';
//     }
// }