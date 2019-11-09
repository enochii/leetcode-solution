// 954. Array of Doubled Pairs
//这个是利用了map的有序性
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        map<int, int> hash;
        for(auto num : A)
        {
            hash[abs(num)]++;
        }
        for(auto pair : hash)
        {
            if(pair.second == 0)
                continue;
            if(pair.second > hash[pair.first * 2])
                return false;
            hash[pair.first * 2] -= pair.second;
        }
        return true;
    }
};

//粗鄙的想法是
//按照绝对值从小到大排序
//很重要的一点是按顺序 找出序对 比如 1 2 4 8
//不能把2和4配对了
class _Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        sort(A.begin(), A.end(), 
            [](const int l, const int r){
                return abs(l) < abs(r);
            }
            );
        
        unordered_map<int, int> mp;
        int cnt = 0;//成功配对的对数
        
        
        for(int num:A)
        {
            if(num % 2 == 0)
            {
                auto it = mp.find(num / 2);
                if(it!=mp.end())
                {
                    //如果存在自己的一半
                    if(--mp[num/2] == 0)
                    {
                        mp.erase(num/2);
                    }
                    
                    cnt++;
                    continue;
                }
                
                // else{
                //     mp[num]++;
                // }
            }
            // else
            {//不存在自己的一半则直接插入
                mp[num]++;
            }
            
        }
        
        return cnt == A.size() / 2;
    }
};