class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), median = nums[n / 2];
        int moves = 0;
        for(int val: nums)
            moves += abs(val - median);
        return moves;
    }
};