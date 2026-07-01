class Solution {
public:
    inline bool check(int x, int y, int n){
        return x >= 0 && x < n && y >= 0 && y < n;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        vector<int> dir = {0, 1, 0, -1, 0};

        int n = grid.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j])
                    q.push({i, j});
            }
        }
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nx = x + dir[i], ny = y + dir[i + 1];
                if(check(nx, ny, n) && grid[nx][ny] == 0){
                    grid[nx][ny] = grid[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        priority_queue<tuple<int, int, int>> pq;
        pq.push({grid[0][0], 0, 0});
        grid[0][0] = -1;
        while(!pq.empty()){
            auto [sf, x, y] = pq.top();
            pq.pop();
            if(x == n - 1 && y == n - 1)
                return sf - 1;
            for(int i = 0; i < 4; i++){
                int nx = x + dir[i], ny = y + dir[i + 1];
                if(check(nx, ny, n) && grid[nx][ny] != -1){
                    pq.push({min(grid[nx][ny], sf), nx, ny});
                    grid[nx][ny] = -1;
                }
            }
        }
        return -1;
    }
};