class Solution {
public:
    int check(unordered_set<int>& set, int num){
        for(int i = 0; i <= num; i++){
            if(set.count(i | (i + 1)) && ((i | (i + 1)) == num))
                return i;

        }
        return -1;
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        for(int& num: nums){
            num = check(set, num);
        }
        return nums;
    }
};