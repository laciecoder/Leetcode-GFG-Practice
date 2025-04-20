class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        for(int val: answers)
            mp[val]++;
        int ans = 0;
        for(auto [val, freq]: mp)
            ans += (val + freq) / (val + 1) * (val + 1);
        return ans; 
    }
};