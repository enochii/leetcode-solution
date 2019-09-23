class Solution_ {
public:
    int longestMountain(vector<int>& A) {
        if(A.size()<2)return 0;
        
        vector<int> left(A.size(),0),right(A.size(),0);
        
        //先来个两遍pass、O(n)空间的解法
        // int cnt=0;
        // int pre=A[0];
        for(int i=1;i<A.size();i++){
            if(A[i]>A[i-1]){
                left[i]=left[i-1]+1;
            }
        }
        for(int i=A.size()-2;i>=0;i--){
            if(A[i]>A[i+1]){
                right[i]=right[i+1]+1;
            }
        }
        
        int max_=0;
        for(int i=0;i<left.size();i++){
            if(left[i]==0||right[i]==0)continue;
            max_=max(max_,left[i]+right[i]+1);
        }
        return max_;
    }
};

//时空看起来好像没有比上面好多少
//分支过多
//就是记录当前是上升状态还是下降状态
//再根据遇到的数决定是否转换状态和start
//

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int ans=0;
        
        int start=0;
        int flag=-1;
        A.push_back(INT_MAX);//边界
        for(int i=1;i<A.size();i++){
            // cout<<flag<<' ';
            if(flag==-1){//上升阶段
                if(A[i-1]<A[i]){
                    
                }else if(A[i]==A[i-1]){
                    start=i;
                }else{//开始下降
                    if(i-1==start){//如果直接下降，没有上升阶段，那么重新开始
                        start=i;
                    }else{
                        flag=1;
                    }
                }
            }
            //
            else{
                if(A[i-1]<=A[i]){
                    ans=max(ans,i-start);
                    start=i-(A[i-1]<A[i]);//重新开始有可能是i也可能是i-1
                    //如果A[i-1]=A[i]，那么就是i喽
                    flag=-1;
                }else{
                    
                }
            }
        }
        return ans;
    }
};