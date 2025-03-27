class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> fmp, smp;
        int n = nums.size();

        for(auto& num: nums)
            smp[num]++;
        
        for(int i = 0; i < n; i++){
            int num = nums[i];
            smp[num]--;
            fmp[num]++;
            if(fmp[num] * 2 > i + 1 && smp[num] * 2 > n - i - 1){
                return i;
            } 
        }

        return -1;
    }
};