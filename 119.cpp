class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex<=1)return vector<int>(rowIndex+1,1);
        queue<int> q;
        q.push(1);q.push(1);
        for(int i=1;i<rowIndex;i++){
            int sz=q.size();
            q.push(1);
            int pre=q.front();q.pop();
            for(int i=1;i<sz;i++){
                q.push(pre+q.front());
                pre=q.front();
                q.pop();
            }
            q.push(1);
        }
        
        vector<int> ans;
        while(q.empty()==false){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};