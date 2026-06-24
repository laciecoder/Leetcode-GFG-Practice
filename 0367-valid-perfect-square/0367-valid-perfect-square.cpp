class Solution {
public:
    bool isPerfectSquare(unsigned long long num) {
        unsigned long long start = 1, end = num;
        while(start <= end){
            unsigned long long mid = start + (end - start) / 2;
            if(mid * mid == num)
                return true;
            if(mid * mid > num){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return false;
    }
};