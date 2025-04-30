class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for(int s: nums)
            if((s >= 10 && s <= 99) || (s >= 1000 && s <= 9999))
                cnt++;
        return cnt;
    }
};