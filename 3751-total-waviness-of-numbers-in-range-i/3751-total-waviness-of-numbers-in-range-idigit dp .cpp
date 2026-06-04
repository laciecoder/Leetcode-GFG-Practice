class Solution {
public:
    vector<long long> dp, pref;
    Solution(){
        long long limit = 1e5+1;
        dp = vector<long long>(limit);
        pref = vector<long long>(limit);
        for(long long i = 100; i < limit; i++){
            int right = i % 10;
            int mid = (i / 10) % 10;
            int left = (i / 100) % 10;
            dp[i] = dp[i / 10] + ((mid > right && mid > left) | (mid < right && mid < left));
            pref[i] = pref[i - 1] + dp[i];
        }
    }
    long long totalWaviness(long long num1, long long num2) {
        return pref[num2] - pref[num1 - 1];
    }
};