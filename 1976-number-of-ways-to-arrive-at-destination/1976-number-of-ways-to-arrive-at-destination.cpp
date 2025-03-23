class Solution {
public:
    int mod = 1e9+7;
    typedef unsigned long long int ull;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<ull, ull>> adj[n];
        for(auto& road: roads){
            ull u = road[0], v = road[1], w = road[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        priority_queue<pair<ull, ull>, vector<pair<ull, ull>>, greater<pair<ull, ull>>> pq;
        pq.push({0, 0});
        vector<ull> distance(n, ULLONG_MAX), path(n, 0ULL);
        distance[0] = 0ULL;
        path[0] = 1ULL;
        while(!pq.empty()){
            auto [wt, v] = pq.top();
            pq.pop();
            for(auto& [nv, nw]: adj[v]){
                if(distance[nv] > wt + nw){
                    distance[nv] = wt + nw;
                    pq.push({distance[nv], nv});
                    path[nv] = path[v] % mod;
                }
                else if(distance[nv] == wt + nw){
                    path[nv] += path[v];
                    path[nv] %= mod;
                }
            }
        }
        return path[n - 1];
    }
};