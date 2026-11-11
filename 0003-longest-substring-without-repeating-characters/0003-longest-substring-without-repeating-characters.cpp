class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> mp(26);
        int start = 0;
        int len = 0;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
            while(mp[s[i]] > 1){
                mp[s[start]]--;
                start++;
            }
            len = max(len, i - start + 1);
        }

        return len;
    }
};