class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int i = 0, j = 0;

        while(i < m && j < n){
            while(i < m && nums1[i] < nums2[j])
                i++;
            while(i < m && j < n && nums2[j] < nums1[i])
                j++;
            if(i < m && j < n && nums1[i] == nums2[j])
                return nums1[i];
        }

        return -1;
    }
};