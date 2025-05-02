class Solution {
public:
    string pushDominoes(string str) {
        str = "L" + str + "R";
        string ans;

        int start = 0;
        for (int i = 1; i < str.size(); i++) {
            if (str[i] == '.')
                continue;
            int span = i - start - 1;
            if (start > 0)
                ans += str[start];
            if (str[start] == str[i])
                ans += string(span, str[start]);
            else if (str[start] == 'L' && str[i] == 'R')
                ans += string(span, '.');
            else
                ans += string(span / 2, 'R') + string(span % 2, '.') +
                       string(span / 2, 'L');
            start = i;
        }

        return ans;
    }
};