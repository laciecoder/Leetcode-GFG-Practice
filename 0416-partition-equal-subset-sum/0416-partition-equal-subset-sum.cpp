class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // long long sum = accumulate(nums.begin(), nums.end(), 0L);
        // int target = sum / 2;
        // if(sum & 1)
        //     return false;
        // unordered_set<int> set;
        // set.insert(0);
        // for(auto num: nums){
        //     if(num > target)    
        //         return false;
        //     unordered_set<int> set2 = set;
        //     for(auto item: set){
        //         int s = num + item;
        //         if(s == target)
        //             return true;
        //         if(s < target)
        //             set2.insert(num + item);
        //     }
        //     set = set2;
        // }
        // return false;

        // bitset logic
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 == 1) 
            return false;
        bitset<10001> b(1);
        for (auto d : nums) 
            b |= b<<d;
        return b[total >> 1];
    }
};