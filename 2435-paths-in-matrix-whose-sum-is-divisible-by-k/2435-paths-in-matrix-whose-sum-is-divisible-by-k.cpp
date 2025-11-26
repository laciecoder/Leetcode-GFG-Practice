class Solution {
public:
    int row = 0, col = 0;
    int solveKrdeBhai(vector<vector<int>>& grid, int i, int j, int k, int sum, vector<vector<vector<int>>>& dp){
        if(i == row || j == col)
            return 0;
        if(dp[i][j][sum] != -1)
            return dp[i][j][sum];
        if(i == row - 1 && j == col - 1){
            return sum % k == 0;
        }
        sum = (sum + grid[i][j]) % k;
        int down = solveKrdeBhai(grid, i + 1, j, k, sum, dp), right = solveKrdeBhai(grid, i, j + 1, k, sum, dp);
        dp[i][j][sum] = down + right;
        return dp[i][j][sum];
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        row = grid.size();
        col = grid[0].size();
        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(k, -1)));
        return solveKrdeBhai(grid, 0, 0, k, 0, dp);
    }
};