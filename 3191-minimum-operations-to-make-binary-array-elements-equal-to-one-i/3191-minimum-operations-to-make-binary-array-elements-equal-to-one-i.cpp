class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i <= n - 3; i++){
            if(nums[i] == 0){
                cnt++;
                nums[i] == 1;
                nums[i + 1] = !nums[i + 1];
                nums[i + 2] = !nums[i + 2];
            }
        }
        if(nums.back() == 0 || nums[n - 2] == 0)
            return -1;
        return cnt;
    }
};