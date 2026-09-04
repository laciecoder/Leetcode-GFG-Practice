class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size(), maxi = nums[0];
        vector<int> mini(n);
        mini[n - 1] = nums[n - 1];
        for(int j = n - 2; j >= 0; j--)
            mini[j] = min(mini[j + 1], nums[j]);
        for(int i = 0; i < n; i++){
            if(maxi - mini[i] <= k)
                return i;
            maxi = max(maxi, nums[i]);
        }
        return -1;
    }
};