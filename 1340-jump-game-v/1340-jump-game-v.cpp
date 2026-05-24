class Solution {
public:
    vector<int> dp;
    int n;
    int solve(vector<int>& arr, int d, int node){
        if(dp[node] != -1)
            return dp[node];
        dp[node] = 1;
        for(int i = node - 1; i >= 0 && node - i <= d && arr[node] > arr[i]; i--){
            dp[node] = max(dp[node], solve(arr, d, i) + 1);
        }
        for(int i = node + 1; i < n && i - node <= d && arr[node] > arr[i]; i++){
            dp[node] = max(dp[node], solve(arr, d, i) + 1);
        }
        return dp[node];
    }
    int maxJumps(vector<int>& arr, int d) {
        int ans = 0;
        n = arr.size();
        dp.assign(n, -1);
        for(int i = 0; i < n; i++)
            ans = max(ans, solve(arr, d, i));
        return ans;
    }
};