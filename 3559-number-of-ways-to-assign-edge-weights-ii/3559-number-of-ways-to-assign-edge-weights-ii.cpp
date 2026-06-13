class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int>& depth, int d, int p, vector<int>& parent){
        depth[node] = d;
        parent[node] = p;
        for(int next: adj[node]){
            if(next == p)
                continue;
            dfs(next, adj, depth, d + 1, node, parent);
        }
    }
    long long binpow(long long a, long long b, long long m){
        long long ans = 1;
        while(b > 0){
            if(b & 1){
                ans = ans * a % m;
            }
            a = a * a % m;
            b >>= 1;
        }
        return ans;
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int k = queries.size();
        int n = edges.size() + 1;
        vector<int> adj[n], depth(n), parent(n), ans(k);
        for(auto edge: edges){
            int u = edge[0] - 1, v = edge[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }   
        dfs(0, adj, depth, 0, -1, parent);
        int log = 0;
        while((1 << log) <= n){
            log++;
        }
        vector<vector<int>> lca(n, vector<int>(log));
        for(int i = 0; i < n; i++){
            lca[i][0] = parent[i];
        }
        for(int i = 1; i < log; i++){
            for(int j = 0; j < n; j++){
                if(lca[j][i - 1] != -1)
                    lca[j][i] = lca[lca[j][i - 1]][i - 1];
            }
        }
        for(int i = 0; i < k; i++){
            int u = queries[i][0] - 1, v = queries[i][1] - 1;
            if(u == v)
                continue;
            if(depth[u] < depth[v])
                swap(u, v);
            int d = depth[u] - depth[v];
            int tu = u, tv = v;
            for(int b = 0; b < log; b++){
                if(d & (1 << b)){
                    u = lca[u][b];
                    if(u == -1)
                        break;
                }
            }
            int l;
            if(u == v){
                l = u;
            }
            else{
                for(int b = log - 1; b >= 0; b--){
                    if(lca[u][b] != lca[v][b]){
                        u = lca[u][b];
                        v = lca[v][b];
                    }
                }
                l = lca[u][0];
            }
            ans[i] = binpow(2, depth[tu] + depth[tv] - depth[l] * 2 - 1, 1e9+7);
        }        
        return ans;
    }
};