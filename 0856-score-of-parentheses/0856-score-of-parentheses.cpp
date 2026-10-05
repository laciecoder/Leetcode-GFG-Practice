class Solution {
public:
    int solve(int l, int r, string& s){
        if(r - l == 1)
            return 1;
        int cnt = 0;

        for(int i = l; i < r; i++){
            if(s[i] == '(')
                cnt++;
            else
                cnt--;
            if(cnt == 0){
                return  solve(l, i, s) + solve(i + 1, r, s);
            }
        }

        return 2 * solve(l + 1, r - 1, s);
    }
    int scoreOfParentheses(string s) {
        return solve(0, s.size() - 1, s);
    }
};