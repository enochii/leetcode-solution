// 1073. Adding Two Negabinary Numbers
// 进位和借位的逻辑相对复杂点
//注意去掉前导0

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        if(arr1.size() < arr2.size()){
            swap(arr1, arr2);
        }
        if(arr2.empty())return arr1;
        
        int p1 = arr1.size() - 1;
        int p2 = arr2.size() - 1;
        int carry = 0;
        
        while(p1 >= 0 && p2 >= 0){
            int res = arr1[p1] + arr2[p2] - carry;
            if(res == -1){
                carry = -1;
                arr1[p1] = 1;//借位
            }else{
                carry = (res >= 2);
                arr1[p1] = res - carry*2;
            }
            
            p1--;p2--;
        }
        
        while(carry && p1>=0){
            int res = arr1[p1] - carry;
            if(res == -1){
                carry = -1;
                arr1[p1] = 1;
            }else{
                carry = (res>=2);
                arr1[p1] = res - carry*2;
            }
            p1--;
        }
        if(carry == 1){
            arr1.insert(arr1.begin(), 1);
            arr1.insert(arr1.begin(), 1);
        } else if(carry == -1){
            arr1.insert(arr1.begin(), 1);
        }
        
        //leading zeros
        while(arr1.size() > 1){
            if(arr1.front() == 0)arr1.erase(arr1.begin());
            else break;
        }
        
        return arr1;
    }
};