class Solution {
public:
    vector<long long> getHashes(vector<int>& arr, int k) {
        const long long BASE = 100007;
        const long long MOD = 1e9 + 7;

        int n = arr.size();
        vector<long long> ans;

        if (k > n || k <= 0)
            return ans;

        long long power = 1;
        for (int i = 1; i < k; i++)
            power = power * BASE % MOD;

        long long h = 0;

        for (int i = 0; i < k; i++)
            h = (h * BASE + arr[i]) % MOD;

        ans.push_back(h);

        for (int i = k; i < n; i++) {
            h = (h - arr[i - k] * power % MOD + MOD) % MOD;
            h = (h * BASE + arr[i]) % MOD;

            ans.push_back(h);
        }

        return ans;
    }
    bool check(vector<int>& nums, int k) {
        vector<long long> hashes = getHashes(nums, k);
        unordered_map<long long, int> mp;
        for(auto val: hashes){
            mp[val]++;
        }
        for(auto&[k, v]: mp){
            if(v == 1)
                return true;
        }
        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int start = 1, end = nums.size();
        int ans = 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (check(nums, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};