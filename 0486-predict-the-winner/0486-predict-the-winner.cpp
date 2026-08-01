class Solution {
public:
    int n;
    pair<int, int> solve(vector<int>& piles, int left, int right, vector<vector<pair<int, int>>>& dp){
        if(left > right)
            return {0, 0};
        if(dp[left][right].first != -1)
            return dp[left][right];    
        pair<int, int> l = solve(piles, left + 1, right, dp);
        pair<int, int> r = solve(piles, left, right - 1, dp);
        if(piles[left] + l.second > piles[right] + r.second)
            return dp[left][right] = {piles[left] + l.second, l.first};
        return dp[left][right] = {piles[right] + r.second, r.first};
    }
    bool stoneGame(vector<int>& piles) {
        n = piles.size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, -1}));
        auto [alice, bob] = solve(piles, 0, n - 1, dp);
        return alice >= bob;
    }
    bool predictTheWinner(vector<int>& nums) {
        return stoneGame(nums);   
    }
};