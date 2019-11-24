//感觉就像是给每一个块石头加上符号
//求得加符号后的最小值
class Solution {
public:
//     int lastStoneWeightII(vector<int>& stones) {
//         const int n = stones.size();
        
//         vector<int> res = {-stones[0], stones[0]};
        
//         for(int i=1;i<n;i++)
//         {
//             vector<int> nres;
//             for(int sum:res)
//             {
//                 nres.push_back(sum+stones[i]);
//                 nres.push_back(abs(sum-stones[i]));
//             }
            
//             res = nres;
//         }
        
//         return *min_element(res.begin(), res.end());
//     }
    
    /*
        1 <= stones.length <= 30
        1 <= stones[i] <= 100
    */
    int lastStoneWeightII(vector<int>& stones) {
        const int n = stones.size();
        
        //hasWeight[i] 表示 是否拥有 子集 的重量为i
        vector<int> hasWeight(1501, 0);
        
        int sum = 0;
        hasWeight[0] = 1;
        for(int sto:stones)
        {
            sum += sto;
            // for(int i=sto; i <= 1500;i++)
            // {
            //     if(hasWeight[i - sto])hasWeight[i] = 1;
            // }
            
            //这里注意要从大到小遍历，否则 sto 可能会被用两次
            for(int i=1500; i >=sto;i--)
            {
                if(hasWeight[i - sto])hasWeight[i] = 1;
            }
        }
        
        for(int i=sum / 2;i>=0;i--)
        {
            if(hasWeight[i])
            {
                // cout << i;
                return (sum-i) - i;
            }
        }
        
        return -1;
    }
};