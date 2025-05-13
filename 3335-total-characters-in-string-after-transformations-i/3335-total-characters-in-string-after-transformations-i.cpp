class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int mod = 1e9 + 7, ans = 0;
        vector<int> dp(t + 26);
        for (int i = 0; i < 26; i++)
            dp[i] = 1;

        for (int i = 26; i < t + 26; i++)
            dp[i] = (dp[i - 26] + dp[i - 25]) % mod;

        for (char ch : s)
            ans = (ans + dp[ch - 'a' + t]) % mod;

        return ans;
    }
};