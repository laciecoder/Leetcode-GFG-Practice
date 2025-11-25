class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        string push = "Push";
        string pop = "Pop";
        vector<string> ans;
        int idx = 0;
        for(int i = 1; i <= n && idx < target.size(); i++){
            ans.push_back(push);
            if(i != target[idx])
                ans.push_back(pop);
            else
                idx++;
        }

        return ans;
    }
};