class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        vector<long long> sums(k, LLONG_MAX >> 1);
        sums[k - 1] = 0;
        long long psum = 0, maxSum = LLONG_MIN;
        for(int i = 0; i < nums.size(); i++){
            psum += nums[i];
            maxSum = max(maxSum, psum - sums[i % k]);
            sums[i % k] = min(sums[i % k], psum);
        }
        return maxSum;
    }
};