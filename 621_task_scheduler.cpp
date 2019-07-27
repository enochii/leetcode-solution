#include <algorithm>
#include <vector>

using namespace std;


//64 ms
//9.6 MB
class _Solution {

public:
    int leastInterval(vector<char>& tasks, int n) {
        int maps[26]={0};
        for(int i=0;i<tasks.size();i++){
            maps[tasks[i]-'A']++;
        }
        //求同存异
        sort(maps, maps+26,greater<int>());
        int times = 0;
        for(;maps[0]>0;){
            int i;
            for(i=0;i<n+1;i++){
                if(maps[i]<=0)break;
                maps[i]--;
            }
            // cout<<i<<' ';
            sort(maps, maps+26,greater<int>());
            times+=maps[0]>0?(n+1):i;
        }
        return times;
    }
};

class Solution {

public:
    //计算空闲时间
    //图参考该题在leetcode的第三种解法
    //设最常出现字母的频率(次数)为f，频率为f的字母共有x个
    //至少使用的interval为si = (f-1)*(n+1)+x
    //如果任务数s小于si，那么结果为si

    //否则结果为s
    //思路：事实上我们做更严格的假设，取y = (s-1)/(n+1)+1行
    //也就是我们现在应该有y*(n+1)个slot，按照之前插入的想法
    //我们总是可以把所有的任务插入这个空间，并且相对第一种情况条件应当是更为宽松
    int leastInterval(vector<char>& tasks, int n) {
        int maps[26] = {0};
        for(char ta:tasks){
            maps[ta-'A']++;
        }
        sort(maps, maps+26);

        int last_line = 0, i = 25;
        while(maps[i] == maps[25]){
            i--;
            last_line++;
        }

        int idle_slots = (maps[25]-1)*(n+1)+last_line;
        // for(int i=25;i>=0 && maps[i]>0;i++){
        //     idle_slots -= maps[i];
        // }

        return max(idle_slots, (int)tasks.size());
    }
};