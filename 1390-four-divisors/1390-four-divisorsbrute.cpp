class Solution {
public:
    vector<long long> getDivisors(long long num){
        vector<long long> ans;

        for(long long i = 1; i <= sqrt(num); i++){
            if(num % i == 0){
                ans.push_back(i);
                if(i != num / i){
                    ans.push_back(num / i);
                }
            }
        }

        return ans;
    }
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;

        for(int num: nums){
            vector<long long> arr = getDivisors(num);
            if(arr.size() == 4)
                sum += accumulate(arr.begin(), arr.end(), 0LL);
        }

        return sum;
    }
};