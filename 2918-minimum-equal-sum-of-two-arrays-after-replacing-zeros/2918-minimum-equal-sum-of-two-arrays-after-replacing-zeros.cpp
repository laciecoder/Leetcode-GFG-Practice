class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0, zero1 = 0, zero2 = 0;
        for(long long n: nums1){
            zero1 += n == 0;
            sum1 += max(n, 1LL);
        }
        for(long long n: nums2){
            zero2 += n == 0;
            sum2 += max(n, 1LL);
        }

        if(sum1 < sum2 && zero1 == 0 || sum1 > sum2 && zero2 == 0)
            return -1;

        return max(sum1, sum2);
    }   
};