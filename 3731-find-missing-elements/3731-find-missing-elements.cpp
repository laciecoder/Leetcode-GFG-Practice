class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<bool> mp(101);
        int mini = INT_MAX, maxi = INT_MIN;
        for(int num: nums){
            mini = min(num, mini);
            maxi = max(maxi, num);
            mp[num] = true;
        }
        vector<int> ans;
        for(int i = mini; i <= maxi; i++){
            if(!mp[i])
                ans.push_back(i);
        }
        return ans;
    }
};