// 441. Arranging Coins
//哦 还可以二分--
//还有看不懂的数学
class Solution {
public:
    int arrangeCoins(int n)
    {
        long ret = 0;
        long sum = 0;
        for(;;ret++)
        {
            if(sum+(ret+1) > n)
            {
                return ret;
            }
            sum += ret+1;
        }
        return -1;
    }
};