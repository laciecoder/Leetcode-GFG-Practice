class Solution {
public:
    int distinctSubseqII(string s) {
        int mod = 1e9+7;
        int n = s.size();
        vector<int> dp(n + 1, 0), last(128, -1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            char ch = s[i - 1];
            dp[i] = (dp[i - 1] * 2) % mod;
            if(last[ch] != -1){
                dp[i] = (dp[i] - dp[last[ch]] + mod) % mod;
            }
            last[ch] = i - 1;
        }
        return (dp[n] - 1 + mod) % mod;
    }
};