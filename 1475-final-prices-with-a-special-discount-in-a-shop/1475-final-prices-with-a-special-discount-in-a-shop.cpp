class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> stack;
        int n = prices.size();
        for(int i = n - 1; i >= 0; i--){
            int curr = prices[i];
            while(!stack.empty() && stack.top() > curr)
                stack.pop();
            if(!stack.empty())
                prices[i] -= stack.top();
            stack.push(curr);
        }
        return prices;
    }
};