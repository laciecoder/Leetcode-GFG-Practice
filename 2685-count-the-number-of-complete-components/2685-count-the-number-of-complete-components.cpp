class Solution {
public:
    class DSU {
    public:
        vector<int> size, parent;

        DSU(int v) {
            size.resize(v + 1, 1);
            parent.resize(v + 1);
            for (int i = 0; i <= v; i++)
                parent[i] = i;
        }

        int findParent(int x) {
            if (parent[x] == x)
                return x;
            return parent[x] = findParent(parent[x]);
        }

        void unionBySize(int u, int v) {
            int pu = findParent(u);
            int pv = findParent(v);
            if (pu == pv)
                return;
            int su = size[pu], sv = size[pv];
            if (su > sv) {
                parent[pv] = pu;
                size[pu] += sv;
            } else {
                parent[pu] = pv;
                size[pv] += su;
            }
        }
    };

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for (auto edge : edges) {
            int u = edge[0], v = edge[1];
            dsu.unionBySize(u, v);
        }

        unordered_map<int, int> edgeCnt;
        int islandCnt = 0;
        for (auto edge : edges) {
            int u = dsu.findParent(edge.front());
            edgeCnt[u]++;
        }

        for (int i = 0; i < n; i++) {
            if (dsu.findParent(i) == i) {
                int cnt = dsu.size[i];
                int totalEdges = (cnt * (cnt - 1)) / 2;
                if (edgeCnt[i] == totalEdges) {
                    islandCnt++;
                }
            }
        }

        return islandCnt;
    }
};
