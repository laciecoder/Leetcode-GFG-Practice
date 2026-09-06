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
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return solve(0, 0, s, t, dp);
    }
};