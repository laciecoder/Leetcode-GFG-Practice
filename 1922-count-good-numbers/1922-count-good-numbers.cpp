class Solution {
public:
    long long myPow(long long x, long long n, long long mod) {
        if(n == 0)
            return 1;
        long long result = 1;
        x = n < 0 ? 1.0 / x : x;
        n = n < 0 ? -1 * n : n;
        while(n > 0){
            if(n & 1){
                result *= x;
                result %= mod;
                n--;
            }
            x*=x;
            x %= mod;
            n/=2;
        }
        return result % mod;
    }
    int countGoodNumbers(long long n) {
        int mod = 1e9+7;
        return (myPow(5, (n + 1) / 2, mod) * myPow(4, n / 2, mod)) % mod;
    }
};