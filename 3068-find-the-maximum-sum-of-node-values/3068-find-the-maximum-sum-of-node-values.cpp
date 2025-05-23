class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long n = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0L);
        long long ans = total;
        for(auto& num: nums)
            num = (num ^ k) - num;
        sort(nums.rbegin(), nums.rend());
        for(int i = 0; i + 1 < n; i += 2){
            total += nums[i] + nums[i + 1];
            ans = max(ans, total);
        }
        return ans;
    }
};