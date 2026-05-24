class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        if(nums.front() < nums.back())
            cnt++;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i - 1])
                cnt++;
        }

        return cnt < 2;
    }
};