//Two Pointers / Greedy

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int last[26]={0};
        for(int i=0;i<S.size();i++){
            last[S[i]-'a']=i;
        }
        //
        vector<int> ans;
        for(int i=0;i<S.size();){
            
            int cur=i;
            int limit=i;
            
            do{
                limit=max(last[S[cur]-'a'],limit);
                cur++;
            }while(cur<=limit);
            //当读到最后一个S[cur]字母就会跳出上面的循环
            ans.push_back(cur-i);
            i=cur;
        }
        
        return ans;
    }
};