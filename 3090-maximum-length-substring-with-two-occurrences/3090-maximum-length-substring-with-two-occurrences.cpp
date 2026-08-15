class Solution {
public:
    int maximumLengthSubstring(string s) {
        int k = 2;
        int len = 0;
        int start = 0;
        int n = s.size();
        vector<int> mp(26, 0);
        for(int i = 0; i < n; i++){
            mp[s[i] - 'a']++;

            while(mp[s[i] - 'a'] > k){
                mp[s[start] - 'a']--;
                start++;
            }
            
            len = max(len, i - start + 1);
        }
        return len;
    }
};