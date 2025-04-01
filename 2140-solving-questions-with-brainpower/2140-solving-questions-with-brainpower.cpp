class Solution {
public:
    long long solve(vector<vector<int>>& questions, int idx, vector<long long>& dp){
        if(idx >= questions.size())
            return 0;
        if(dp[idx] != -1)
            return dp[idx];
        long long noTake = solve(questions, idx + 1, dp);
        long long take = questions[idx][0] + solve(questions, idx + questions[idx][1] + 1, dp);
        return dp[idx] = max(take, noTake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);
        for(int idx = n - 1; idx >= 0; idx--){
            long long noTake = dp[idx + 1];
            long long take = questions[idx][0] + dp[min(idx + questions[idx][1] + 1, n)];
            dp[idx] = max(take, noTake);
        }
        return dp[0];
    }
};