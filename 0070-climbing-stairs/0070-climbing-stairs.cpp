class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 0, c = 0;
        while(n--){
            c = a + b;
            b = a;
            a = c;
        }
        return a;
    }
};