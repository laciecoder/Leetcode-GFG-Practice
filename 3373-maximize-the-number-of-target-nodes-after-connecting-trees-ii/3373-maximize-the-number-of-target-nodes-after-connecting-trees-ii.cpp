class Solution {
public:
    int dfs(int i, int p, const vector<vector<int>>& adj, vector<bool>& parity,
            bool even = true) {
        int targets = even;
        parity[i] = even;
        for (int j : adj[i])
            if (j != p)
                targets += dfs(j, i, adj, parity, !even);
        return targets;
    }
    vector<vector<int>> adjacencyList(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size() + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return adj;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        int m = edges1.size() + 1, n = edges2.size() + 1;
        vector<bool> parity(m), ingnored(n);
        int even1 = dfs(0, -1, adjacencyList(edges1), parity), odd1 = m - even1;
        int even2 = dfs(0, -1, adjacencyList(edges2), ingnored), odd2 = n - even2;
        vector<int> res(m);
        for (int i = 0; i < m; ++i)
            res[i] = max(even2, odd2) + (parity[i] ? even1 : odd1);
        return res;
    }
};