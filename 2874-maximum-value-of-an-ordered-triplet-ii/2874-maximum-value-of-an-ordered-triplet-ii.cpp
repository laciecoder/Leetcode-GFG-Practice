class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0, diff = 0, i = 0;
        for(long long k: nums){
            ans = max(ans, diff * k);
            diff = max(diff, i - k);
            i = max(k, i);
        }
        return ans;
    }
};