class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }
    int gcdOfOddEvenSums(int n) { return gcd(n * n, n * (n + 1)); }
};