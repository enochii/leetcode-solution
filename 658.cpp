// 658. Find K Closest Elements

#include <vector>

using namespace std;

//二分后往两边扩散
//用下标记录结果，一次性构造结果数组即可
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int pos=bsearch(arr,x);
        // if(pos==arr.size()){
        //     //TODO
        // }
        
        int l,r;
        l=pos-1;
        // vector<int> ans;

        if(arr[pos]==x){
            r=pos+1;
            // ans.push_back(x);
            // cout<<x;
            k--;
        }else{
            r=pos;
        }
        bool lflag=false,rflag=false;
        int lval,rval;
        while(k>0){
            
            if(!lflag&&l>=0){
                lval=arr[l];
                lflag=true;
            }
            if(!rflag&&r<arr.size()){
                rval=arr[r];
                rflag=true;
            }
            // int next_val;
            if(lflag&&rflag){
                if(x-lval<=rval-x){
                    lflag=false;
                    l--;
                }else{
                    rflag=false;
                    r++;
                }
            }else if(lflag){
                lflag=false;
                l--;
            }else{
                rflag=false;
                r++;
            }

            k--;
        }
        return vector<int>(arr.begin()+(l+1),arr.begin()+r);
    }

    //返回x所在或者应该插入的下标
    int bsearch(vector<int>& arr,int x){
        int l=0,r=arr.size();
        while(l<r){
            int mid=(l+r)/2;
            if(arr[mid]>=x){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};