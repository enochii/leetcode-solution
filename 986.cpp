// 986. Interval List Intersections

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int pa = 0, pb = 0;
        while(pa < A.size() && pb < B.size()){
            if(A[pa][1] > B[pb][1]){
                if(A[pa][0] > B[pb][1]){
                    
                }else{
                    ans.push_back({max(A[pa][0], B[pb][0]), B[pb][1]});
                }
                pb++;
            }else if(A[pa][1] < B[pb][1]){
                if(A[pa][1] < B[pb][0]){
                    
                }else{
                    ans.push_back({max(A[pa][0], B[pb][0]), A[pa][1]});
                }
                pa++;
            }else{
                ans.push_back({max(A[pa][0], B[pb][0]), A[pa][1]});
                pa++;pb++;
            }
        }
        return ans;
    }
};