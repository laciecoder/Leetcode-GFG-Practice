class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size(), count = 0;
        for(int i = 0; i < n; i++){
            count += ((i + 1) * ('z' - s[i] + 1));
        }
        return count;
    }
};