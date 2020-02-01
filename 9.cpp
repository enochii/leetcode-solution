class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)return false;
        
        //
        vector<int> bits ;
        while(x)
        {
            bits.push_back(x%10);
            x /= 10;
        }
        
        for(int i=0;i<bits.size()/2;i++)
        {
            if(bits[i] != bits[bits.size()-i-1])
            {
                return false;
            }
        }
        
        return true;
    }
};  