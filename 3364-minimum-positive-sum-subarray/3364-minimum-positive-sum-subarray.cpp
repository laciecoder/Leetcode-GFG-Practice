class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        vector<int> pref(n + 1, 0);

        for(int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];

        multiset<int> st;
        int ans = INT_MAX;

        for(int i = 1; i <= n; i++) {

            int add = i - l;
            if(add >= 0)
                st.insert(pref[add]);

            int rem = i - r - 1;
            if(rem >= 0)
                st.erase(st.find(pref[rem]));

            auto it = st.lower_bound(pref[i]);

            if(it != st.begin()) {
                --it;
                ans = min(ans, pref[i] - *it);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};