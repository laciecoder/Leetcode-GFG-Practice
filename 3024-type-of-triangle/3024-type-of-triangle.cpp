class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0], b = nums[1], c = nums[2];
        if(a == b && b == c)
            return "equilateral";
        if(a == b || b == c || a == c)
            return "isosceles";
        if(a + b <= c || b + c <= a || c + a <= b)
            return "none";
        return "scalene";
    }
};