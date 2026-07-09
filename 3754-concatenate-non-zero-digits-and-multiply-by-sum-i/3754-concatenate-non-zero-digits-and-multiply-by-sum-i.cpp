class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0, ans = 0;
        long long base = 1, multiplier = 10;
        while(n > 0){
            long long v = n % 10;
            n /= 10;
            sum += v;
            if(v > 0){
                ans = base * v + ans;
                base *= multiplier; 
            }
        }
        return ans * sum;
    }
};