class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minPos = 0, maxPos = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[minPos] > nums[i]){
                minPos = i;
            }
            if(nums[maxPos] < nums[i]){
                maxPos = i;
            }
        }
        // making calc easier
        if(minPos > maxPos){
            swap(minPos, maxPos);
        }
        // 3 case: remove corners, remove till maxPos, remove till minPos from back;
        int a = minPos + 1 + n - maxPos;
        int b = maxPos + 1; //n - (n - maxPos - 1)
        int c = n - minPos;
        return min({a, b, c});
    }
};