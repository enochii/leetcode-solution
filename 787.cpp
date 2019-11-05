// 787. Cheapest Flights Within K Stops



// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
//         vector<vector<pair<int,int> >> graph(n);
//         for(auto& f:flights){
//             graph[f[0]].emplace_back(f[1], f[2]);
//         }
//         // vector<int> vis(n, 0);
//         vector<vector<int>> price(2, vector<int>(n, INT_MAX));
        
//         queue<int> q;
//         q.push(src);
//         // vis[src] = 1;
//         price[0][src] = 0;
        
//         // int price = INT_MAX;
//         int curK = 0;
        
//         while(!q.empty()){
//             if(curK++ > K)break;
//             int sz = q.size();
            
//             for(int i=0;i<sz;i++){
//                 int top = q.front();q.pop();
//                 // cout<<top<<": " <<price[0][top] <<"| "; 
                
//                 for(auto& p : graph[top]){
//                     // vis[p.first] = 1;
//                     q.push(p.first);
//                     price[1][p.first] = min({price[0][top]+p.second, price[0][p.first], price[1][p.first]});
//                 }
//             }
//             // cout <<'\n';
//             // cout<< price[1][dst] << ' ' <<price[1][4] <<'\n';
//             price[0] = price[1];
//         }
        
//         return price[0][dst] == INT_MAX?-1:price[0][dst];
//     }
// };

//bell-man ford
//对于K的限制问题
//用二维数组来解决
//滚动减少内存使用
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> price(2, vector<int>(n, INT_MAX));
        price[0][src] = price[1][src] = 0;
        
        //总共是K+1条边
        for(int i=0;i<K+1;i++){
            for(auto & f:flights){
                if(price[0][f[0]] != INT_MAX){
                    price[1][f[1]] = min(price[0][f[0]] + f[2], price[1][f[1]]);
                }
            }
            price[0] = price[1];
        }
        
        return INT_MAX == price[0][dst]? -1:price[0][dst];
    }
};