class Solution {
public:
    int solve(int idx, int tidx, string& s, string& t, vector<vector<int>> &dp){
        int tn = t.size(), sn = s.size();
        if(idx == sn || tidx == tn){
            return tidx == tn;
        }
        if(dp[idx][tidx] != -1)
            return dp[idx][tidx];
        int ans = 0;
        if(t[tidx] == s[idx]){
            ans = solve(idx + 1, tidx + 1, s, t, dp);
        }
        ans += solve(idx + 1, tidx, s, t, dp);
        return dp[idx][tidx] = ans;
    }
    int numDistinct(string s, string t) {
        // vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        // return solve(0, 0, s, t, dp);
        int m = s.size(), n = t.size();
        vector<vector<unsigned int>> dp(m + 1, vector<unsigned int>(n + 1, 0));
        for(int i = 0; i <= m; i++)
            dp[i][n] = 1;
        
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                dp[i][j] = dp[i + 1][j];
                if(s[i] == t[j])
                    dp[i][j] += dp[i + 1][j + 1];
            }
        }
        return dp[0][0];
    }
};