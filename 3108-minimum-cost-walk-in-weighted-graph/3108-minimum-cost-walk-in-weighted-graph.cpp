class Solution {
public:
    vector<int> parent, depth;
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& queries) {
        parent.resize(n, -1);
        depth.resize(n, 0);
        vector<unsigned int> componentCost(n, -1);
        for (auto& edge : edges)
            Union(edge[0], edge[1]);
        for (auto& edge : edges)
            componentCost[find(edge[0])] &= edge[2];
        vector<int> answer;
        for (auto& query : queries) 
            if (find(query[0]) != find(query[1]))
                answer.push_back(-1);
            else
                answer.push_back(componentCost[find(query[0])]);
        return answer;
    }

private:
    int find(int node) {
        return parent[node] == -1 ? node : parent[node] = find(parent[node]);
    }
    void Union(int node1, int node2) {
        int root1 = find(node1), root2 = find(node2);
        if (root1 == root2)
            return;
        if (depth[root1] < depth[root2])
            swap(root1, root2);
        parent[root2] = root1;
        if (depth[root1] == depth[root2])
            depth[root1]++;
    }
};
