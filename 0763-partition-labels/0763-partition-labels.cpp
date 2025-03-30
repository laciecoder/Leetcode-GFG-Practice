class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++)
            mp[s[i]] = i;
        int j(0), anchor(0);
        vector<int> ans;
        for(int i = 0; i < s.size(); i++){
            j = max(j, mp[s[i]]);
            if(i == j){
                ans.push_back(i - anchor + 1);
                anchor = i + 1;
            }
        }
        return ans;
    }
};