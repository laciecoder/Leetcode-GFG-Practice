class Solution {
public:
    bool check(vector<int>& candies, long long k, int mid){
        long long ans = 0;
        for(int i = 0; i < candies.size(); i++){
            ans += (candies[i] / mid);
        }
        return ans >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int start = 1, end = *max_element(candies.begin(), candies.end());
        int ans = 0;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(check(candies, k, mid)){
                ans = mid;
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return ans;
    }
};