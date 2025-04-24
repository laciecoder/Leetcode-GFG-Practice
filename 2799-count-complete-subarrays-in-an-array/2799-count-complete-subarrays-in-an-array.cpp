class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        int n = nums.size(), unique = set.size(), start = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (mp[nums[i]] == 0)
                unique--;
            mp[nums[i]]++;
            while (unique == 0) {
                mp[nums[start]]--;
                if (mp[nums[start]] == 0)
                    unique++;
                start++;
            }
            cnt += start;
        }
        return cnt;
    }
};
