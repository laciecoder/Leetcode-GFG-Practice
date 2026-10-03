class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stack;
        stack.push(-1);
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                stack.push(i);
            else {
                stack.pop();
                if (stack.empty())
                    stack.push(i);
                else
                    ans = max(ans, i - stack.top());
            }
        }
        return ans;
    }
};