class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        int INF = INT_MAX;
        int NINF = INT_MIN;
        int count = 0;
        vector<int> lower(26, NINF), upper(26, INF);
        for(int i = 0; i < n; i++){
            char ch = word[i];
            if(ch >= 'A' && ch <= 'Z'){
                int pos = ch - 'A';
                upper[pos] = min(upper[pos], i);
            }
            else{
                int pos = ch - 'a';
                lower[pos] = max(lower[pos], i);
            }
        }
        for(int i = 0; i < 26; i++){
            if(upper[i] != INF && lower[i] != NINF && lower[i] < upper[i])
                count++;
        }
        return count;
    }
};