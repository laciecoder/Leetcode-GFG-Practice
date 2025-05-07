class Solution {
public:
    int dir[5] = {0, 1, 0, -1, 0};
    typedef tuple<int, int, int> tup;
    int minTimeToReach(vector<vector<int>>& adj) {
        int row = adj.size(), col = adj[0].size(), INF = 1e9;
        vector<vector<int>> dp(row, vector<int>(col, INF));
        priority_queue<tup, vector<tup>, greater<tup>> pq;
        pq.push({0, 0, 0});
        adj[0][0] = -1;
        while(!pq.empty()){
            auto [score, x, y] = pq.top();
            pq.pop();
            if(score >= dp[x][y])
                continue;
            if(x == row - 1 && y == col - 1)
                return score;
            dp[x][y] = score;
            for(int i = 0; i < 4; i++){
                int nx = x + dir[i], ny = y + dir[i + 1];
                if(nx >= 0 && nx < row && ny >= 0 && ny < col && dp[nx][ny] == INF)
                    pq.push({max(adj[nx][ny], score) + 1, nx, ny});
            }
        }
        return -1;
    }
};