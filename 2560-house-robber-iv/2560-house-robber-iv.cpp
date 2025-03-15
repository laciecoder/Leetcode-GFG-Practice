class Solution {
public:
    bool check(vector<int>& nums, int  k, int mid){
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= mid){
                count++;
                i++;
            }
        }
        return count >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int start = INT_MAX, end = INT_MIN;
        for(auto& num: nums){
            start = min(start, num);
            end = max(end, num);
        }
        int ans = 0;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(check(nums, k, mid)){
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