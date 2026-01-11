class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int temp = 0;
            set<int> set;
            for(int j = i; j < n; j++){
                temp += nums[j];
                set.insert(nums[j]);
                count += set.count(temp);
            }
        }
        return count;
    }
};