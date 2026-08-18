class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int fcnt = 0, scnt = 0;
        int n = nums.size();

        if(n == k)
            return *max_element(nums.begin(), nums.end());
        if(k == 1){
            map<int, int> mp;
            for(int val: nums){
                mp[val]++;
            }
            for(auto it = mp.rbegin(); it != mp.rend(); it++){
                auto [k, v] = *it;
                cout << k << ' ' << v << endl;
                if(v == 1)
                    return k;
            }
            return -1;
        }
        if(nums[0] == nums[n - 1] && n > k){
            return -1;
        }
        for(int val: nums){
            if(val == nums[0])
                fcnt++;
            if(val == nums[n - 1])
                scnt++;
        }
        if(nums[0] == nums[n - 1] && n <= k)
            return nums[0];
        if(fcnt > 1 && scnt > 1)
            return -1;
        if(fcnt > 1)
            return nums[n - 1];
        if(scnt > 1)
            return nums[0];
        return max(nums[0], nums[n - 1]);
    }
};