class Solution {
public:
    string convertToBase7(int num) {
        string ans;
        if(num < 0){
            num *= -1;
            ans.push_back('-');
        }
        while(num >= 7){
            ans.push_back(num % 7 + '0');
            num /= 7;
        }
        ans.push_back(num + '0');
        reverse(ans.begin() + (ans.front() == '-' ? 1 : 0), ans.end());
        return ans;
    }
};