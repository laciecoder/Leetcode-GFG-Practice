class Solution {
public:
    int m, n;
    int dir[5] = {0, 1, 0, -1, 0};
    inline bool check(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    // brute 4^(m*n)
    bool solve(vector<vector<int>>& grid, int i, int j, int health){
        if(health <= 0)
            return false;
        if(grid[i][j] == 1)
            health--;
        if(i == m - 1 && j == n - 1){
            return health > 0;
        }
        for(int k = 0; k < 4; k++){
            int x = i + dir[k], y = j + dir[k + 1];
            if(check(x, y) && grid[x][y] != -1){
                int copy = grid[i][j];
                grid[i][j] = -1;
                bool ans = solve(grid, x, y, health);
                if(ans)
                    return true;
                grid[i][j] = copy;
            }
        }
        return false;
    }
    // optimal nlogn dijkstra
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        n = grid[0].size();
        m = grid.size();
        vector<vector<int>> visited(m, vector<int>(n));
        priority_queue<tuple<int, int, int>> q; // health, i, j
        if(grid[0][0])
            health--;
        if(health == 0)
            return false;
        q.push({health, 0, 0});
        visited[0][0] = health;
        while(!q.empty()){
            auto [h, i, j] = q.top();
            q.pop();
            for(int k = 0; k < 4; k++){
                int ni = i + dir[k], nj = j + dir[k + 1];
                if(check(ni, nj)){
                    int nh = h - grid[ni][nj];
                    if(nh && visited[ni][nj] < nh){
                        visited[ni][nj] = nh;
                        q.push({nh, ni, nj});
                    }
                }
            }
        }


        return visited[m - 1][n - 1] > 0;
    }
};