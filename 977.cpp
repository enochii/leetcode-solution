class Solution {
    //确定最小(绝对值)两边跑嗷
public:
    vector<int> sortedSquares(vector<int>& A) {
        const int sz=A.size();
        int pos=0;
        while(pos<A.size()){
            if(A[pos]>=0)break;
            pos++;
        }
        if(pos==sz)pos--;
        //
        if(pos>0&&-A[pos-1]<A[pos]){
            pos--;
        }
        //
        vector<int> ans={A[pos]*A[pos]};
        int left=pos-1, right=pos+1;
        while(left>=0&&right<sz){
            int l=A[left]*A[left];
            int r=A[right]*A[right];
            if(l<r){
                ans.push_back(l);
                left--;
            }else{
                ans.push_back(r);
                right++;
            }
        }
        while(left>=0){
            ans.push_back(A[left]*A[left]);
            left--;
        }
        while(right<sz){
            ans.push_back(A[right]*A[right]);
            right++;
        }
        
        return ans;
    }
};