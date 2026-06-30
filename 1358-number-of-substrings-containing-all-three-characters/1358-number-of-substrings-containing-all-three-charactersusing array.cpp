class Solution {
public:
    int numberOfSubstrings(string s) {
        int mp[3] = {0};
        int i = 0, j = 0;
        int n = s.size(), ans = 0;

        while(i < n){
            mp[s[i] - 'a']++;
            while(mp[0] && mp[1] && mp[2]){
                mp[s[j] - 'a']--;
                ans += (n - i);
                j++;
            }
            i++;
        }

        return ans;
    }
};