class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mini(n), maxi(n);
        maxi[0] = nums[0];
        mini[n - 1] = nums[n - 1];
        for(int i = 1, j = n - 2; i < n; j--, i++){
            maxi[i] = max(nums[i], maxi[i - 1]);
            mini[j] = min(mini[j + 1], nums[j]);
        }

        for(int i = 0; i < n; i++){
            if(maxi[i] - mini[i] <= k)
                return i;
        }

        return -1;
    }
};