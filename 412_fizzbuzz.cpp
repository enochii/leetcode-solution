#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        //用手工cnt来避免 % 操作
        int cnt3=0,cnt5=0;

        vector<string> ans;
        for(int i=0;i<n;i++){
            cnt3++;cnt5++;
            if(cnt3==3){
                cnt3=0;
                ans.push_back(cnt5==5?(cnt5=0,"FizzBuzz"):"Fizz");
            }else if(cnt5==5){
                cnt5=0;
                ans.push_back("Buzz");
            }else{
                ans.push_back(to_string(i+1));
            }
        }
        return ans;
    }
};