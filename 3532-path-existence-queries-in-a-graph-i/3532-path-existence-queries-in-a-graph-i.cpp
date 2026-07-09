class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> prefix(n);
        for(int i = 1; i < n; i++){
            prefix[i] = (nums[i] - nums[i - 1] <= maxDiff ? 1 : 0) + prefix[i - 1];
        }
        int qn = queries.size();
        vector<bool> ans(qn);
        for(int i = 0; i < qn; i++){
            int u = queries[i][0], v = queries[i][1];
            if(u == v){
                ans[i] = true;
                continue;
            }
            int dist = v - u;
            int nv = prefix[v], nu = prefix[u];
            int actdist = nv - nu;
            if(dist == actdist)
                ans[i] = true;
        }
        return ans;
    }
};