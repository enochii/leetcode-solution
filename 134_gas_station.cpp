#include <vector>

using namespace std;

class _Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        for(int i=0;i<gas.size();i++){
            if(gas[i]<cost[i]){
                continue;
            }
            int next=(i+1)%gas.size();
            int left=(gas[i]-cost[i]);

            while(next!=i){
                left+=(gas[next]-cost[next]);
                if(left<0){
                    break;
                }
                next=(next+1)%gas.size();
            }
            if(next==i)return i;
        }

        return -1;
    }
};

//我们可以先筛一下
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum=0;
        int valid_start=0;
        for(int i=0;i<gas.size();i++){
            sum+=gas[i]-cost[i];
            if(sum<0){
                sum=0;
                valid_start=i+1;
            }
        }
        if(valid_start==gas.size())return -1;
        //也就是说，至少从valid_start到结尾是没有问题的
        //在valid_start之前开始都不行
        //贪心一下
        //容易想到，既然从valid_start开始走到末尾至少不会爆炸
        //由于前面可以为后面省下非负的gas，那么valid_start肯定就是最好的起点
        int next=0;
        while(next!=valid_start){
            sum+=(gas[next]-cost[next]);
            if(sum<0)return -1;
            next=(next+1)%gas.size();
        }
        return valid_start;
    }
};