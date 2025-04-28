class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long n = nums.size(), ans = 0, total = 0, start = 0;

        for(int i = 0; i < n; i++){
            total += nums[i];
            while(start <= i && total * (i - start + 1) >= k){
                total -= nums[start];
                start++;
            }
            ans += i - start + 1;
        }

        return ans;
    }
};