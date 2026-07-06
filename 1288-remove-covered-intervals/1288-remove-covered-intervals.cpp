class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b){
            int s1 = a[0], s2 = b[0], e1 = a[1], e2 = b[1];
            if(s1 != s2)
                return s1 < s2;
            return e1 >= e2;
        });
        int cnt = 0;
        int maxEnd = 0;
        for(auto& interval: intervals){
            if(interval[1] > maxEnd){
                cnt++;
                maxEnd = interval[1];
            }
        }
        return  cnt;
    }
};