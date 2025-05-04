class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<vector<int>, int> mp;
        int ans = 0;
        for(auto domino: dominoes){
            sort(domino.begin(), domino.end());
            ans += mp[domino]++;
        }
        return ans;
    }
};