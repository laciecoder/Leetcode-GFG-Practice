class Solution {
public:
    vector<int> dir = {-1, 0, 1, 0, -1};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<pair<int, int>> arr(queries.size());
        for (int i = 0; i < queries.size(); i++)
            arr[i] = {queries[i], i};
        sort(arr.begin(), arr.end());
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({grid[0][0], {0, 0}});
        int row = grid.size(), col = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        visited[0][0] = true;
        for (auto [qv, idx] : arr) {
            while (!pq.empty() && pq.top().first < qv) {
                auto [val, coor] = pq.top();
                pq.pop();
                auto [x, y] = coor;
                count++;
                for (int i = 0; i < 4; i++) {
                    int dx = x + dir[i], dy = y + dir[i + 1];
                    if (dx >= 0 && dx < row && dy >= 0 && dy < col &&
                        !visited[dx][dy]) {
                        visited[dx][dy] = true;
                        pq.push({grid[dx][dy], {dx, dy}});
                    }
                }
            }
            queries[idx] = count;
        }
        return queries;
    }
};