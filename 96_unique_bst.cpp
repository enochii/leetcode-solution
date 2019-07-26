#include <vector>

using namespace std;

class _Solution {

    vector<int> mem;
public:
    //印象里这和出栈次序一个东西
    //看成是有一个中序序列，可以有多少颗二叉树
    //该序列的出栈次序正好决定了二叉树的结构
    
    int numTrees(int n) {
        mem.assign(n+1, -1);
        
        mem[0]=1;
        mem[1]=1;
        return recur(n);
    }
    
    int recur(int n){
        if(mem[n] != -1){
            return mem[n];
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=recur(i)*recur(n-1-i);
        }
        return mem[n]=sum;
    }
};


class Solution {

    vector<int> mem;
public:
    //印象里这和出栈次序一个东西
    //看成是有一个中序序列，可以有多少颗二叉树
    //该序列的出栈次序正好决定了二叉树的结构
    
    int numTrees(int n) {
        mem.assign(n+1, 0);
        
        mem[0]=1;
        mem[1]=1;
        
        //自底向上的dp
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                mem[i]+=mem[j]*mem[i-1-j];
                // cout<<'s';
            }
            // cout<<mem[i];
        }
        // cout << mem[0] << ' ' << mem[1] <<' '<<mem[2]<<' '<<mem[3]<<'\n';

        return mem[n];
    }
};