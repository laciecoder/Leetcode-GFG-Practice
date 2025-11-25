class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans = 0;
        stack<string> stack;
        auto isOperator = [](string token) {
            return token == "+" || token == "-" || token == "*" || token == "/";
        };
        auto operate = [](char op, int a, int b) {
            switch(op){
                case '+':
                    return a + b;
                case '-':
                    return a - b;
                case '*':
                    return a * b;
                case '/':
                    return b / a;
            }
            return 0;
        };
        for(string token: tokens){
            if(isOperator(token)){
                int a = stoi(stack.top());
                stack.pop();
                int b = stoi(stack.top());
                stack.pop();
                int c = operate(token[0], a, b);
                stack.push(to_string(c));
            }
            else{
                stack.push(token);
            }
        }
        return stoi(stack.top());
    }
};