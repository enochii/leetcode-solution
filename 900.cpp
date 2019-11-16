// 900. RLE Iterator

class RLEIterator {
    typedef vector<int> :: iterator It;
    int pos = 0;
    It it;
    It end;
    
public:
    RLEIterator(vector<int>& A) 
    {
        it = A.begin();
        end = A.end();
        pos = 0;
    }
    
    int next(int n) 
    {
        while(n > 0 && it != end)
        {
            if (*it >= n)
            {
                auto ret = *(it+1);
                *it -= n;
                if(*it == 0)
                {
                    it+=2;
                }
                return ret;
            }else{
                n -= *it;
                it += 2;
            }
        }
        
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */