class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        map<int, int> mp;
        int cnt = 0;
        int maxi = -1, mini = 101;
        int n = nums.size();
        for(int v: nums){
            mp[v]++;
            maxi = max(maxi, v);
            mini = min(mini, v);
        }
        if(maxi <= k && mp[maxi] != n || mini < k)
            return -1;
        for(auto [v, c]: mp)
            if(v > k)
                cnt++;
        return cnt; 
    }
};