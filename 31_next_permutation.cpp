#include <algorithm>
#include <vector>
// #include <iterator>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto first = nums.begin(), last = nums.end();
        if(first == last)return;//size == 0
        auto i = last;
        if(--i==first)return;//size == 1
        while (true)
        {
            auto i1 = i;
            if(*--i<*i1){
                auto i2 = last;
                while(!(*i<*--i2));
                iter_swap(i, i2);
                std::reverse(i1, last);
                return;
            }
            if(i==first){
                std::reverse(first, last);//回归原位
                return;
            }
        }
    }
};