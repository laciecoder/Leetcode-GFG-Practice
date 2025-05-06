class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int s = nums.size();
        for(int i = 0; i < s; i++){
            nums[i] = nums[i] +  (nums[nums[i]] % s ) * s;
        }
        for(int i= 0; i < s; i++){
            nums[i] /=  s;
        }
        return nums;
    }
};