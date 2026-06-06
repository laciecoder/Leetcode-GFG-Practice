class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n);
        for(int i = 1; i < n; i++){
            left[i] = left[i - 1] + nums[i - 1];
            right[n - i - 1] = right[n - i] + nums[n - i];
        }
        for(int i = 0; i < n; i++){
            left[i] = abs(left[i] - right[i]);
        }
        return left;
    }
};