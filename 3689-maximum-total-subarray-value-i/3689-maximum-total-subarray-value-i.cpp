class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        auto [min, max] = minmax_element(nums.begin(), nums.end());
        return (*max - *min) * 1LL * k;
    }
};