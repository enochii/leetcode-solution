// 349. Intersection of Two Arrays
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int p1 = 0, p2 = 0;
        const int n1 = nums1.size(), n2 = nums2.size();
        
        while(p1 < n1 && p2 < n2){
            if(nums1[p1] == nums2[p2]){
                ans.push_back(nums1[p1]);
                while(p1+1 < n1 && nums1[p1] == nums1[p1+1])++p1;
                ++p1;
                
                while(p2+1 < n2 && nums2[p2] == nums2[p2+1])++p2;
                ++p2;
            }else if(nums1[p1] < nums2[p2]){
                ++p1;
            }else{
                ++p2;
            }
        }
        return ans;
    }
};