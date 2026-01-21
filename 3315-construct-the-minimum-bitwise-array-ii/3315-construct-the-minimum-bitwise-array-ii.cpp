class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            int d = 1;
            int res = -1;
            while((nums[i] & d) != 0){
                res = nums[i] - d;
                d <<= 1;
            }
            ans[i] = res;
        }
        return ans;
    }
};