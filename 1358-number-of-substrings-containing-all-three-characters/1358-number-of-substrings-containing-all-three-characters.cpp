class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> set;
        int i = 0, j = 0;
        int ans = 0;
        int n = s.size();
        while(i < n){
            set[s[i]]++;
            while(set.size() == 3){
                set[s[j]]--;
                ans+=n - i;
                if(set[s[j]] == 0){
                    set.erase(s[j]);
                }
                j++;
            }
            i++;
        }
        return ans;
    }
};