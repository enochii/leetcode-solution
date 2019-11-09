// 670. Maximum Swap

#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) 
    {
        vector<int> lastPos(10, 0);

        string s = to_string(num);
        for(int i=0;i<s.size();i++)
        {
            lastPos[s[i] - '0'] = i;
        }

        for(int i=0;i<s.size();i++)
        {
            for(int digit = 9;digit>=0;digit--)
            {
                if(s[i]-'0' < digit && i < lastPos[digit])
                {
                    swap(s[i], s[lastPos[digit]]);
                    int ret = 0;
                    for(int i=0;i<s.size();i++)
                    {
                        ret = ret * 10 + s[i] - '0';
                    }

                    return ret;
                }
            }
        }

        return num;
    }
};

//O(dlog(d))
class _Solution {
public:
    int maximumSwap(int num) {
        vector<int> digits;

        //提取num的每个位
        while (num)
        {
            digits.push_back(num % 10);
            num /= 10;
        }
        //reverse
        reverse(digits.begin(), digits.end());

        const int n = digits.size();
        vector<int> index(n, 0);
        for(int i=0;i<n;i++)
        {
            index[i] = i;
        }

        sort(index.begin(), index.end(),[&digits](const int li, const int ri){
            return digits[li] > digits[ri];
        });

        for(int i=0;i<n;i++)
        {
            //由于sort不是稳定的，所以注意判重
            if(index[i] != i && digits[i] != digits[index[i]])
            {
                //要交换的digit
                int dig = digits[index[i]];

                //要找到最后一个digit
                //考虑 1993 1要和第二个9换，而不是第一个9
                int swap_index = index[i];
                for(int j=index[i]+1;j<n;j++)
                {
                    if(digits[j] == dig)
                    {
                        swap_index = j;
                    }
                }

                swap(digits[i], digits[swap_index]);
                break;
            }
        }

        //
        int ret = 0;
        for(int i=0;i<n;i++)
        {
            ret = ret * 10 + digits[i];
        }

        return ret;
    }
};