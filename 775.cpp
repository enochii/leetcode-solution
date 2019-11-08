class Solution {
public:
    bool isIdealPermutation(vector<int>& A) 
    {
        //一个数只能小于它前面紧邻着的数 或者 后面的数
        int mx = INT_MIN;
        for(int i=1;i<A.size();i++)
        {
            if(A[i] < mx)return false;
            
            mx = max(mx, A[i-1]);
        }
        return true;
    }
};


//merge sort nlogn
class _Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        //归并排序求逆序对
        int local = 0;
        for(int i=1;i<A.size();i++)
        {
            if(A[i-1] > A[i])++local;
        }
        
        //
        int glo = calGlobal(A.begin(), A.end());
        // cout << glo <<' '<<local;
        return glo == local;
    }
    
    typedef vector<int>::iterator It;
    int calGlobal(It beg, It end)
    {
        int n = end - beg;
        if(n <= 1)return 0;
        
        auto mid = beg + n / 2;
        int lcg = calGlobal(beg, mid);
        int rcg = calGlobal(mid, end);
        
        vector<int> tmp;
        tmp.reserve(n);
        auto l = beg, r = mid;
        
        int cnt = 0;
        while(l != mid || r != end)
        {
            if(r == end)
            {
                tmp.push_back(*l++);
            }else if(l == mid)
            {
                tmp.push_back(*r++);
            }
            //
            else if(*l < *r){
                tmp.push_back(*l++);
            }else{
                tmp.push_back(*r++);
                cnt+= mid - l;//位于前半段中大于*r的数
            }
        }
        
        for(int num:tmp)
        {
            *beg++ = num;
        }
        
        return cnt + lcg + rcg;
    }
};