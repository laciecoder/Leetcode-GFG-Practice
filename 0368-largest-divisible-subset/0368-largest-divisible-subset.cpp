class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n), prev(n), ans;
        sort(nums.begin(), nums.end());
        int max = 0, idx = -1;
        for(int i = 0; i < n; i++){
            count[i] = 1;
            prev[i] = -1;
            for(int j = i - 1; j >= 0; j--){
                if(nums[i] % nums[j] == 0){
                    if(1 + count[j] > count[i]){
                        count[i] = count[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if(count[i] > max){
                max = count[i];
                idx = i;
            }
        }
        while(idx != -1){
            ans.push_back(nums[idx]);
            idx = prev[idx];
        }
        return ans;
    }
};