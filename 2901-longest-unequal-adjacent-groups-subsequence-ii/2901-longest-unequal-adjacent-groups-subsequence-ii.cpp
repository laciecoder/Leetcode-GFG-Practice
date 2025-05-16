class Solution {
public:
    bool hamming(string& a, string& b){
        int hamming = 0;
        for(int i = 0; i < a.size() && hamming <= 1; i++){
            if(a[i] != b[i])
                hamming++;
        }
        return hamming == 1;
    }
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<vector<int>> dp(n);
        for(int i = 0; i < n; i++)
            dp[i].push_back(i);
        int maxLength = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(groups[j] != groups[i] && words[i].size() == words[j].size()){
                    if(hamming(words[i], words[j])){
                        if(dp[j].size() + 1 > dp[i].size()){
                            dp[i] = dp[j];
                            dp[i].push_back(i);
                            maxLength = max(maxLength, int(dp[i].size()));
                        }
                    }
                }
            }
        }
        vector<string> ans;
        for(auto v: dp){
            if(v.size() == maxLength){
                for(auto idx: v){
                    ans.push_back(words[idx]);
                }
                break;
            }
        }
        return ans;
    }
};