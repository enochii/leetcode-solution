#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> mem;
        mem.insert(n);
        while(n!=1){
            n=cal(n);
            if(mem.count(n))return false;
            mem.insert(n);
        }
        return true;
    }

    int cal(int n){
        int newn=0;
        while(n){
            int bit=n%10;
            n/=10;
            newn+=bit*bit;
        }
        return newn;
    }
};