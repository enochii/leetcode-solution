// 752. Open the Lock

class Solution {
    char up(char c){
        ++c;
        return c > '9'? '0':c;
    }
    char down(char c){
        --c;
        return c < '0'?'9':c;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        //bfs
        string start = "0000";
        
        //deads can also used to be a "visited" hashset?
        unordered_set<string> deads;
        for(auto &s : deadends){
            deads.insert(s);
        }
        
        queue<string> q;
        if(deads.count(start))return -1;
        q.push(start);
        int step = 0;
        while(!q.empty()){
            const int sz = q.size();
            for(int time = 0; time < sz; time++){
                auto& top = q.front();
                
                if(top==target)return step;
                string s = top;
                
                
                for(int i=0;i<4;i++){
                    
                    char c = s[i];
                    s[i] = up(c);
                    if(!deads.count(s)){
                        q.push(s);
                        deads.insert(s);
                    }
                    s[i] = down(c);
                    if(!deads.count(s)){
                        q.push(s);
                        deads.insert(s);
                    }
                    s[i] = c;//reset
                }
                q.pop();
            }
            step ++;
        }
        return -1;
    }
};