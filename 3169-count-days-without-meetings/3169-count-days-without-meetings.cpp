class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<vector<int>> result;
        for(auto i: meetings)
            if (result.empty() || result.back()[1] < i[0]) result.push_back(i);
            else  result.back()[1] = max(i[1], result.back()[1]); 
        int ans = result[0][0] - 1;
        for(int i = 1; i < result.size(); i++)
            ans += (result[i][0] - result[i - 1][1]) - 1;
        return ans + (days - result.back().back());
    }
};