class Solution {
public:
    typedef long long ll;
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<ll> arr(n - 1);
        for(int i = 0; i < n - 1; i++)
            arr[i] = weights[i] + weights[i + 1];
        sort(arr.begin(), arr.end());

        ll ans = 0;
        for(int i = 0; i < k - 1; i++){
            ans += arr[n - 1 - i - 1] - arr[i];
        }
        return ans;
    }
};