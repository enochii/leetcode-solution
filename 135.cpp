//135. Candy
//T:O(nlogn) S:O(n)
class _Solution {
public:
    int candy(vector<int>& ratings) {
        const int n = ratings.size();
        vector<int> index(n);
        for(int i = 0;i<index.size();i++){
            index[i] = i;
        }
        
        //sort index by their corresponding rating
        //根据rating给生成的下标数组排序
        //按rating大小顺序分糖果
        auto cmp = [&ratings](int i, int j){
            return ratings[i] < ratings[j];
        };
        
        sort(index.begin(), index.end(), cmp);
        
        vector<int> cans(n, 0);
        int ans = 0;
        for(int i=0;i<index.size();i++){
            int cur = index[i];
            
            cans[cur] = 1;//至少一个糖果
            if(cur > 0 && ratings[cur] > ratings[cur-1] && cans[cur-1] > 0)
                cans[cur] = cans[cur-1]+1;
            if(cur<n-1 && ratings[cur] > ratings[cur+1] && cans[cur+1]>0)
                cans[cur] = max(cans[cur], cans[cur+1]+1);
            ans += cans[cur];
        }
        return ans;
    }
};

//O(n)
//扫描两遍
class Solution {
public:
    int candy(vector<int>& ratings) {
        const int n = ratings.size();
        vector<int> cans(n, 1);
        
        for(int i=1;i<n;i++){
            if(ratings[i-1] < ratings[i] && cans[i-1] >= cans[i]){
                cans[i] = cans[i-1]+1;
            }
        }
        
        for(int i=n-1;i>0;i--){
            if(ratings[i-1] > ratings[i] && cans[i-1] <= cans[i]){
                cans[i-1] = cans[i]+1;
            }
        }
        
        return accumulate(cans.begin(),cans.end(),0);
    }
};