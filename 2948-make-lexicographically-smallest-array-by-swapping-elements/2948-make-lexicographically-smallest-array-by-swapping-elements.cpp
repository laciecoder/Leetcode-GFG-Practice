class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> arr(n), brr(n);
        for(int i = 0; i < n; i++){
            arr[i] = {nums[i], i};
        }
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n; i++){
            brr[i] = {arr[i].second, arr[i].first};
        }
        int start = 0;
        for(int i = 1; i < n; i++){
            if(brr[i].second - brr[i - 1].second > limit){
                sort(brr.begin() + start, brr.begin() + i);
                start = i;
            }
        }    
        sort(brr.begin() + start, brr.end());
        for(int i = 0; i < n; i++){
            nums[brr[i].first] = arr[i].first;
        }

        return nums;
    }
};