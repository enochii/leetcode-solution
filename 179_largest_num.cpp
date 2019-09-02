#include <string>
#include <vector>
#include <algorithm>

//为让数更大，把数字转成字符串
//还有一个技巧是这个cmp的实现...

struct cmp{
    bool operator()(string l, string r){
        return l+r>r+l;

        //如果r是l的前缀，那么就比较r和(l减去r后的部分)
        //否则直接比较
        //这个自己写的版本会报std::length_error
        //也就是超过max_size，不懂
        //另外，我觉得思路是有问题的
        // int pos;
        // for(pos=0;pos<r.size()&&pos<l.size();pos++){
        //     if(l[pos]!=r[pos])return l[pos]>r[pos];
        // }
        // //来到这里，一个str是另一个str的prefix
        // if(l.size()==r.size()){
        //     return true;//相等耶！无所谓了
        // }
        // if(l.size()<r.size()){
        //     r=r.substr(pos);
        // }else{
        //     l=l.substr(pos);
        // }
        // return this->operator()(l,r);
    }
};

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> snums;
        for(int num:nums){
            snums.push_back(to_string(num));
        }
        sort(snums.begin(),snums.end(),cmp());
        //
        string res="";
        for(string& str:snums){
            res.append(str);
        }
        int pos=0;
        while(res[pos]=='0')pos++;//删除前导0
        if(pos==res.size())pos--;//注意单个0的情况
        return res.substr(pos);
    }
};