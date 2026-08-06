class Solution {
public:
    int pod(int n){
        int prod = 1;
        while(n && prod){
            prod *= (n % 10);
            n /= 10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        int temp = n;
        while(pod(temp) % t != 0){
            temp++;
        }
        return temp;
    }
};