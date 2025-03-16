class Solution {
public:
    bool check(vector<int>& ranks, long long cars, long long mid){
        long long count = 0;
        for(long long rank: ranks){
            long long temp = sqrt(mid / rank);
            count += temp;
        }
        return count >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long start = 1, end = 1LL * ranks[0] * cars * cars;
        long long ans = 0;
        while(start <= end){
            long long mid = start + (end - start) / 2;
            if(check(ranks, cars, mid)){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
    }
};