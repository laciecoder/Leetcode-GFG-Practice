class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd = INT_MAX;
        for(int num: nums1){
            if(num & 1)
                odd = min(odd, num);
        }
        if(odd == INT_MAX)
            return true;

        for(int num: nums1){
            if(!(num & 1) && num < odd)
                return false;
        }

        return true;
    }
};