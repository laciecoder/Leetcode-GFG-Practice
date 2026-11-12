class Solution {
public:
    int solve(vector<int>& arr){
        int n = arr.size();
        int prev = arr[0];
        int len = 1;
        int ans = 1;
        for(int i = 1; i < n; i++){
            if(prev < arr[i]){
                len++;
            }
            else{
                len = 1;
            }
            prev = arr[i];
            ans = max(ans, len);
        }
        return ans;
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        int a = solve(nums);
        reverse(nums.begin(), nums.end());
        int b = solve(nums);
        return max(a, b);
    }
};