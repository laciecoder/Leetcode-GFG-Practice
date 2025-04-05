class Solution {
public:
    // int solve(vector<int>& nums, int sum, int idx){
    //     if(idx == nums.size())
    //         return sum;
    //     int take = solve(nums, sum ^ nums[idx], idx + 1);
    //     int notake = solve(nums, sum, idx + 1);
    //     return take + notake;
    // }
    int subsetXORSum(vector<int>& nums) {
        // return solve(nums, 0, 0);
        int sum = 0;
        for(auto n: nums)
            sum |= n;
        return sum << (nums.size() - 1);
    }
};