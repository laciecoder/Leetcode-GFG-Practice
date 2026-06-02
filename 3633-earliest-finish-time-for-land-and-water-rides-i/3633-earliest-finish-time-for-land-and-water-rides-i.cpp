class Solution {
public:
    int solve(vector<int>& ra, vector<int>& ta, vector<int>& rb, vector<int>& tb){
        int ans = INT_MAX;
        int m = ra.size(), n = rb.size();
        int curr = INT_MAX;
        for(int i = 0; i < m; i++){
            curr = min(curr, ra[i] + ta[i]);
        }
        for(int i = 0; i < n; i++){
            if(rb[i] >= curr){
                ans = min(ans, rb[i] + tb[i]);
            }
            else{
                ans = min(ans, curr + tb[i]);
            }
        }
        return ans;
    }
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        return min(solve(ls, ld, ws, wd), solve(ws, wd, ls, ld));
    }
};