#include <string>
#include <vector>

using namespace std;

//最直接的方法，二维dp
//O(1)空间的解法可以从中心点(1或者2的字符串)向两边展开
//我dp真的菜...记得搞好dp迭代的顺序
class Solution {
public:
    int countSubstrings(string s) {
        const int len = s.size();
        vector<vector<bool>> palin(len, vector<bool>(len,false));
        int cnt=0;
        for(int i=0;i<len;i++){
            palin[i][i]=true;//sz=1
            cnt++;
        }
        
        for(int i=0;i<len-1;i++){
            if(s[i]==s[i+1]){
                palin[i][i+1]=true;
                cnt++;
            }
        }
        for(int sz=3;sz<len;sz++){
            for(int i=0;i+sz<=len;i++){
                int j = i+sz-1;
                if(s[i]==s[j]&&palin[i+1][j-1]){
                    palin[i][j] = true;
                    cnt++;
                    // if(i==0&&j==4)cout<<'!';
                }
            }
        }
        return cnt;
    }
};