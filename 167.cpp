#include <vector>

using namespace std;

//Two Sum II
//two pointer
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=1,right=numbers.size();
        //直接双指针，又有点sliding的味道
        int sum=numbers[left-1]+numbers[right-1];
        while(sum!=target&&left<right){//两个index不同
            if(sum<target){
                sum=numbers[left++]+numbers[right-1];
            }else{
                sum=numbers[left-1]+numbers[right-2];
                right--;
            }
        }
        return {left,right};
    }
};