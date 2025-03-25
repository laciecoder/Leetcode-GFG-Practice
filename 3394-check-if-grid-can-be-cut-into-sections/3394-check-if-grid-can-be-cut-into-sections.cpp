class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        auto check = [&](vector<vector<int>>& arr) -> bool {
            int ans = 0;
            int prev = arr[0][1];
            for (auto& p : arr) {
                int x = p[0], y = p[1];
                ans += (prev <= x);
                prev = max(prev, y);
            }
            return ans > 1;
        };
        vector<vector<int>> a, b;
        for (auto& p : rectangles) {
            a.push_back({p[0], p[2]});
            b.push_back({p[1], p[3]});
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return check(a) || check(b);
    }
};