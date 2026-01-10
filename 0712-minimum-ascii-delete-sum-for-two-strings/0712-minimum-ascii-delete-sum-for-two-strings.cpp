class Solution {
public:
    int solveKrdeBhai(string& a, string& b, int i, int j, vector<vector<int>>& dp){
        if(i == a.size()){
            return accumulate(b.begin() + j, b.end(), 0);
        }
        if(j == b.size()){
            return accumulate(a.begin() + i, a.end(), 0);
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        if(a[i] == b[j])
            return dp[i][j] = solveKrdeBhai(a, b, i + 1, j + 1, dp);
        return dp[i][j] = min(solveKrdeBhai(a, b, i + 1, j, dp) + a[i], solveKrdeBhai(a, b, i, j + 1, dp) + b[j]);
    }
    int minimumDeleteSum(string a, string b) {
        int m = a.size(), n = b.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // return solveKrdeBhai(a, b, 0, 0, dp);
        for(int i = 1; i <= n; i++){
            dp[0][i] = dp[0][i - 1] + b[i - 1];
        }

        for(int i = 1; i <= m; i++){
            dp[i][0] = dp[i - 1][0] + a[i - 1];
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(a[i - 1] == b[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = min({dp[i - 1][j] + a[i - 1], dp[i][j - 1] + b[j - 1]});
                }
            }
        }

        return dp[m][n];
    }
};