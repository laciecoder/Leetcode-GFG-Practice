class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int len = 0;
        unordered_map<int, int> mp;
        int n = nums.size();
        int start = 0;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
            while(mp[nums[i]] > k){
                mp[nums[start]]--;
                start++;
            }
            len = max(len, i - start + 1);
        }
        return len;
    }
};