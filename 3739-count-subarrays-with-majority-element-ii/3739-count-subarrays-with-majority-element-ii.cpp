class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size(), pref = n + 1;
        vector<long long> count(2 * n + 2), acc(2 * n + 2);
        long long ans = 0;
        count[pref] = acc[pref] = 1;
        for(int i = 0; i < n; i++){
            pref += (nums[i] == target ? 1 : -1);
            count[pref]++;
            acc[pref] = count[pref] + acc[pref - 1];
            ans += acc[pref - 1];
        }

        return ans;
    }
};