class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int count = 1;
        int num = 1;
        for(int i = 1; i <= k; i++){
            if(num % k == 0)
                return count;
            num = (num * 10 + 1) % k;
            count++;
        }

        return -1;
    }
};