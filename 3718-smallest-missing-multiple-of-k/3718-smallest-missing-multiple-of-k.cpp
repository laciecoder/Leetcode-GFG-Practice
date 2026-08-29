class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> set;
        for(int v: nums)
            set.insert(v);
        int start = k;
        while(set.count(start))
            start += k;
        return start;
    }
};