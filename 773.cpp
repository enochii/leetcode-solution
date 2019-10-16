//773. Sliding Puzzle
class Solution {
    using ht = unordered_set<string>;
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        //bfs
        //一个board编码为一个状态
        
        string end = "123450";
        
        string start;
        for(auto& vec:board){
            for(int i : vec){
                start.push_back(char(i+'0'));
            }
        }
        queue<string> q;
        
        
        q.push(start);
        ht vis;
        vis.insert(start);
        
        int step = 0;
        while(!q.empty()){
            const int sz = q.size();
            for(int i=0;i<sz;i++){
                auto &top = q.front();
                if(top == end)return step;
                generate(q, top, vis);
                q.pop();
            }
            step++;
        }
        return -1;
    }
    
    inline
        void generate(queue<string>& q, string& s, ht& vis){
        int pos = 0;
        while(pos < s.size() && s[pos] != '0'){
            pos++;
        }
        
        int r = pos / 3;
        int c = pos - r*3;
        
        int dir[5] = {1,0,-1,0,1};
        for(int i=0;i<4;i++){
            int nr = r + dir[i];
            int nc = c + dir[i+1];
            
            if(nr < 0 || nc < 0 || nr > 1 || nc >2)continue;
            int npos = nr*3+nc;
            // if(npos < 0 || npos > 5)continue;//error -> (0, 4)
            swap(s[pos], s[npos]);
            if(!vis.count(s)){
                vis.insert(s);
                q.push(s);
            }
            swap(s[pos], s[npos]);
        }
    }
};