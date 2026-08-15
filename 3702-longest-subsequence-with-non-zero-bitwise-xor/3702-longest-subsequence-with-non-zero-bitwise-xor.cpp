class Solution {
public:
    // int solve(int idx, int xorr, int count, vector<int>& nums){
    //     if(idx == nums.size()){
    //         return xorr > 0 ? count : 0;
    //     }
    //     int take = solve(idx + 1, xorr ^ nums[idx], count + 1, nums);
    //     int notake = solve(idx + 1, xorr, count, nums);
    //     return max(take, notake);
    // }
    int longestSubsequence(vector<int>& nums) {
        int xorr = 0;
        int zeroCnt = 0;
        int n = nums.size();
        for(int num: nums){
            xorr ^= num;
            zeroCnt += (num == 0);
        }
        if(zeroCnt == n)
            return 0;
        return xorr > 0 ? n : n - 1;
    }
};