// 841. Keys and Rooms
//dfs
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n, false);
        
        dfs(0, rooms, vis);
        
        for(int v:vis){
            if(!v)return false;
        }
        return true;
    }
    
    void dfs(int cur, vector<vector<int>>& rooms, vector<int> &vis){
        if(vis[cur])return;
        
        vis[cur] = true;
        for(int next : rooms[cur]){
            dfs(next, rooms, vis);
        }
    }
};