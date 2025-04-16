class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int end = -1, cnt = 0;
        long long ans = 0;
        unordered_map<int, int> mp;
        for(int start = 0; start < n; start++){
            while(cnt < k && end + 1 < n){
                end++;
                cnt += mp[nums[end]]++;
            }
            if(cnt >= k){
                ans += n - end;
            }
            --mp[nums[start]];
            cnt -= mp[nums[start]];
        }
        return ans;
    }
};