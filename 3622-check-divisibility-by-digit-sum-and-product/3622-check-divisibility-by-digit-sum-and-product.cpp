class Solution {
public:
    bool checkDivisibility(int n) {
        int copy = n;
        int prod = 1, sum = 0;
        while(copy){
            int rem = copy % 10;
            copy /= 10;
            prod *= rem;
            sum += rem;
        }
        return (n % (sum + prod) == 0);
    }
};