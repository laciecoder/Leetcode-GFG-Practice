class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long ans = 0, sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(long long n: nums){
            sum += (n % modulo == k);
            ans += mp[(sum - k + modulo) % modulo];
            mp[sum % modulo]++;
        }
        return ans;
    }
};