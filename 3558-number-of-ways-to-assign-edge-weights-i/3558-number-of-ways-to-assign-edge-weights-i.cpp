class Solution {
public:
    int dfs(int node, vector<int> adj[]){
        if(adj[node].size() == 0)
            return 0;
        int ans = 0;
        for(int next: adj[node]){
            ans = max(ans, 1 + dfs(next, adj));
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
            adj[min(u, v)].push_back(max(u, v));
        }
        int len = dfs(0, adj);
        int mod = 1e9+7;
        return binexp(2, len - 1, mod);
    }
};