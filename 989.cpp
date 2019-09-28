// 989. Add to Array-Form of Integer

//所以这种进位题就是考虑左右操作数完没完
//再加上carry位
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        reverse(A.begin(), A.end());
        const int sz = A.size();
        
        int index = 0;
        int carry = 0;
        while(K){
            int res = K%10+carry;
            K/=10;
            if(index < sz){
                res+=A[index];
                A[index] = res % 10;
                index++;
            }else{
                A.push_back(res % 10);
            }
            
            carry = res >= 10;
        }
        
        //到这里K已经用完了
        while(carry){
            if(index<sz){
                int res=A[index] + carry;
                carry = res >= 10;
                A[index] = res % 10;
                index++;
            }else{
                A.push_back(1);
                carry = 0;//最后一个进位
            }
        }
        
        reverse(A.begin(),A.end());
        
        return A;
    }
};