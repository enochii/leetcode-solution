// 264. Ugly Number II

class _Solution {
public:
    typedef long type;
    int nthUglyNumber(int n) {
        priority_queue<type, vector<type>, greater<type>> pq;
        pq.push(1);
        
        unordered_set<type> st;
        
        type top;
        while(n--){
            top = pq.top();
            // cout<<top<<'\n';
            
            pq.pop();
            push(top*2,pq,st);
            push(top*3,pq,st);
            push(top*5,pq,st);
        }
        
        return top;
    }
    
    inline void push(type v, priority_queue<type, vector<type>, greater<type>>& pq, unordered_set<type>& st){
        if(st.count(v))return;
        pq.push(v);
        st.insert(v);
    }
};

class Solution {
//丑数必然是某个丑数乘以2/3/5
public:
    typedef long type;
    int nthUglyNumber(int n) {
        vector<long> ugly(n+1, 1);
        int i2 = 1, i3 = 1, i5 = 1;
        
        //感觉就是在模拟heap
        for(int i=2;i<=n;i++){
            long num = min(ugly[i2]*2l, min(ugly[i3]*3l, ugly[i5]*5l));
            if(num == ugly[i2]*2){
                i2++;
            }
            if(num == ugly[i3]*3){
                i3++;
            }
            if(num == ugly[i5]*5){
                i5++;
            }
            ugly[i] = num;
        }
        
        return ugly.back();
    }
};