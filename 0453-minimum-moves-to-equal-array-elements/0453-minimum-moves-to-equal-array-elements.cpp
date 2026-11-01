class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, diff = 0;
        for(int i = nums.size() - 1; i > 0; i--){
            diff = nums[i] - nums[0];
            ans += diff;
        }
        return ans;
    }
};