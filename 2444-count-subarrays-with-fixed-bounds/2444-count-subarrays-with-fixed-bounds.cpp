class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        bool mini = false, maxi = false;
        int start = 0, minIdx = 0, maxIdx = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < minK || nums[i] > maxK){
                mini = maxi = false;
                // this too how to move window
                start = i + 1;
            }
            if(nums[i] == minK){
                mini = true;
                minIdx = i;
            }
            if(nums[i] == maxK){
                maxi = true;
                maxIdx = i;
            }
            if(mini && maxi)
                // this is the crux of this problem;
                ans += (min(minIdx, maxIdx) - start + 1);
        }
        return ans;
    }
};