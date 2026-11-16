class Solution {
public:
    string digitSum(string s, int k) {
        if(s.size() <= k)
            return s;
        string ans;
        int n = s.size();
        for(int i = 0; i < n; i += k){
            int sum = 0;
            for(int j = i; j < min(n, i + k); j++)
                sum += (s[j] - '0');
            ans = ans + to_string(sum);
        }
        return digitSum(ans, k);
    }
};