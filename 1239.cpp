//对26个字母做并查集
//再根据这个信息把所有的string分并查集
//这样会得到不相交的一个或者多个集合
//复杂度有点高... 跟每个字符串的长度有关

//把每个string编码成一个26 bit的long long
//做与运算就可以判断 是否unique

// 1239. Maximum Length of a Concatenated String with Unique Characters
//backtracking

class Solution {
    int ans = 0;
public:
    int maxLength(vector<string>& arr) 
    {
        vector<long long> codes;
        codes.reserve(arr.size());
        for(auto & s: arr)
        {
            codes.push_back(encode(s));
        }
        
        backtrack(arr, codes, 0, 0, 0);
        
        return ans;
    }
    
private:
    void backtrack(vector<string>& arr, vector<long long> &nums, int pos, int cur, int len)
    {
        if(pos == arr.size())
        {
            ans = max(ans, len);
            return;
        }
        
        for(int i=pos;i<arr.size();i++)
        {
            if(nums[i] != -1 && (cur & nums[i]) == 0)
            {
                // cout << cur <<' ' << i <<'\n';
                backtrack(arr, nums, i+1, cur | nums[i], len + arr[i].size());
            }
        }
        ans = max(ans, len);
        //end
    }
    
    long long encode(const string &s)
    {
        long long ret = 0;
        for(char c : s)
        {
            long long xi = ret & (1<<(c-'a'));
            if(xi)return -1;
            ret |= (1<<(c-'a'));
        }
        
        return ret;
    }
};