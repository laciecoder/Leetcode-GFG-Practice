class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int start = 0, ans = 0, temp = 0;
        for(int i = 0; i < nums.size(); i++){
            while((temp & nums[i])){
                temp ^= nums[start++];
            }
            temp |= nums[i];
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};