#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    vector<int> ori, cur;
public:
    Solution(vector<int>& nums) {
        ori=cur=nums;
        // sort(cur.begin(),cur.end());
    }
    
    //我没搞懂这道题的reset
    //原意是希望每个permutation被列出来的可能性是相同的
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        // sort(cur.begin(),cur.end());
        return ori;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        next_permutation(cur.begin(),cur.end());
        return cur;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */