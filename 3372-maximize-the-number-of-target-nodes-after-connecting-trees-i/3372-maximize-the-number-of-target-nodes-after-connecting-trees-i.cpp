class Solution {
public:
    int dfs(int i, int p, vector<vector<int>>& adj, int k){
        if(k <= 0)
            return k == 0;
        int ans = 1;
        for(int j: adj[i])
            if(j != p)
                ans += dfs(j, i, adj, k - 1);
        return ans;
    }

    vector<vector<int>> getList(vector<vector<int>>& edges){
        vector<vector<int>> adj(edges.size() + 1);
        for(auto& edge: edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int m = edges1.size() + 1, n = edges2.size() + 1, maxi = 0;
        vector<vector<int>> adj1 = getList(edges1), adj2 = getList(edges2);
        vector<int> ans(m);
        for(int i = 0; i < n; i++)
            maxi = max(maxi, dfs(i, -1, adj2, k - 1));
        for(int i = 0; i < m; i++)
            ans[i] = maxi + dfs(i, -1, adj1, k);
        return ans;
    }
};