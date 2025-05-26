class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size(), ans = 0, nodeCnt = 0;
        vector<vector<int>> adj(n), count(n, vector<int>(26));
        vector<int> indegree(n);
        vector<int> q;
        for(auto edge: edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }    
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0)
                q.push_back(i);
        }
        while(!q.empty()){
            vector<int> qq;
            for(auto i: q){
                nodeCnt++;
                ans = max(ans, ++count[i][colors[i] - 'a']);
                for(auto j: adj[i]){
                    for(int k = 0; k < 26; k++){
                        count[j][k] = max(count[j][k], count[i][k]);
                    }
                    if(--indegree[j] == 0)
                        qq.push_back(j);
                }
            }
            swap(q, qq);
        }
        return nodeCnt != n ? -1 : ans;
    }
};