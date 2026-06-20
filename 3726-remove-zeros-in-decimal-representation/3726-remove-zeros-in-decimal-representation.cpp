class Solution {
public:
    long long removeZeros(long long n) {
        long long ans = 0;
        long long mul = 1;
        while(n > 0){
            long long num = n % 10;
            if(num > 0){
                ans = num * mul + ans;
                mul *= 10;
            }
            n /= 10;
        }
        return ans;
    }
};