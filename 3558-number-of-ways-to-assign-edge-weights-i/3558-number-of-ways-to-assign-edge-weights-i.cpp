class Solution {
public:
    int dfs(int node, int parent, vector<int> adj[]){
        int ans = 0;
        for(int next: adj[node]){
            if(next == parent)
                continue;
            ans = max(ans, 1 + dfs(next, node, adj));
        }
        return ans;
    }
    unsigned long long binexp(unsigned long long base, unsigned long long pow, unsigned long long mod){
        unsigned long long ans = 1;
        while(pow > 0){
            if(pow & 1){
                ans = ans * base % mod;
            }
            base = base * base % mod;
            pow >>= 1;
        }
        return ans;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> adj[n];
        for(auto edge: edges){
            int u = edge[0] - 1, v = edge[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int len = dfs(0, -1,adj);
        int mod = 1e9+7;
        return binexp(2, len - 1, mod);
    }
};