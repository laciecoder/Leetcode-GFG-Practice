class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int prefix = nums[0];
        int ans = 0;
        int idx = 1;
        for(int i = 1; i < n; i++){
            if(i > 0 && nums[i - 1] + 1 == nums[i]){
                prefix += nums[i];
            }
            else{
                idx = i;
                break;
            }
        }
        sort(nums.begin() + idx, nums.end());
        for(int i = idx - 1; i < n; i++){
            if(nums[i] == prefix)
                prefix++;
        }
        return prefix;
    }
};