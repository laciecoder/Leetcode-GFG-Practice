class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        for(auto& row: grid)
            arr.insert(arr.end(), row.begin(), row.end());
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(abs(arr[n / 2] - arr[i]) % x > 0)
                return -1;
            ans += abs(arr[n / 2] - arr[i]) / x;
        }
        return ans;
    }
};