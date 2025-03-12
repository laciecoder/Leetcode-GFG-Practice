class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int lb = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int ub = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();
        return max((int)nums.size() - ub, lb);
    }
};