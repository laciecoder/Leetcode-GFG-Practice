class Solution {
public:

    int dijkstra(vector<pair<int, int>> adj[], int n){
        vector<int> distance(n, INT_MAX), visited(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        distance[0] = 0;
        pq.push({0, 0});
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            auto [wt, x] = p;
            if(x == n - 1)
                return distance[x];
            if(visited[x])
                continue;
            visited[x] = 1;
            for(auto [y, w]: adj[x]){
                if(distance[x] + w < distance[y]){
                    distance[y] = distance[x] + w;
                    pq.push({distance[y], y});
                }
            }
        }
        return -1;
    }

    int minCost(int n, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[n];

        for(vector<int> edge: edges){
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 2 * w});
        }

        return dijkstra(adj, n);
    }
};