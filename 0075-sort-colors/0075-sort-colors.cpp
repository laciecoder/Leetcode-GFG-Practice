class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroIdx = 0, twoIdx = nums.size() -1, i = 0;
        while(i <= twoIdx)
            if(nums[i] == 0)
                swap(nums[i++], nums[zeroIdx++]);
            else if(nums[i] == 2)
                swap(nums[i], nums[twoIdx--]);
            else
                i++;
    }
};