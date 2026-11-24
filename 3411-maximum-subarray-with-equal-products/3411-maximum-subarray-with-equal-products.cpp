class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 2, start = 0, product = 1;
        for(int i = 0; i < nums.size(); i++){
            while(gcd(product, nums[i]) > 1)
                product /= nums[start++];
            product *= nums[i];
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};