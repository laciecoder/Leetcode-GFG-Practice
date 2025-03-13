class Solution {
public:
    bool bs(vector<int>& nums, vector<vector<int>>& queries, int mid){
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        bool ans = true;
        for(int i = 0; i < mid; i++){
            int start = queries[i][0], end = queries[i][1], maxi = queries[i][2];
            prefix[start] += maxi;
            prefix[end + 1] -= maxi;
        }
        ans = prefix[0] >= nums[0];
        for(int j = 1; j < n; j++){
            prefix[j] += prefix[j - 1];
            ans &= (prefix[j] >= nums[j]);
        }
        return ans;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int maxVal = *max_element(nums.begin(), nums.end());
        if(maxVal == 0)
            return 0;
        int start = 1, end = queries.size();
        int ans = -1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(bs(nums, queries, mid)){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
    }
};