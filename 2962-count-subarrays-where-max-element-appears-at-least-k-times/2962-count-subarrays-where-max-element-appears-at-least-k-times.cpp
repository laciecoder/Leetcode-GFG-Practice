class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // typical template 250 ms memory beats 8%
        // unordered_map<int, int> mp;
        // long long cnt = 0, maxElem = INT_MIN;
        // for(auto& n: nums)  maxElem = max(maxElem, (long long)n);
        // for(int end = 0, start = 0; end < nums.size(); end++){
        //     mp[nums[end]]++;
        //     while(mp[maxElem] >= k){
        //         mp[nums[start]]--;
        //         start++;
        //     }
        //     cnt+=start;
        // }
        // return cnt;

        // optimal 130ms memory beats 98%
        long long cnt = 0, me = *max_element(nums.begin(), nums.end());
        for(int end = 0, start = 0; end < nums.size(); end++){
            if(nums[end] == me)
                k--;
            while(k == 0){
                if(nums[start] == me)
                    k++;
                start++;
            }
            cnt += start;
        }
        return cnt;
    }
};